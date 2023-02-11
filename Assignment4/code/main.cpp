#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>

std::vector<cv::Point2f> control_points;

void mouse_handler(int event, int x, int y, int flags, void *userdata) 
{
    if (event == cv::EVENT_LBUTTONDOWN && control_points.size() < 4) 
    {
        std::cout << "Left button of the mouse is clicked - position (" << x << ", "
        << y << ")" << '\n';
        control_points.emplace_back(x, y);
    }     
}

void naive_bezier(const std::vector<cv::Point2f> &points, cv::Mat &window) 
{
    auto &p_0 = points[0];
    auto &p_1 = points[1];
    auto &p_2 = points[2];
    auto &p_3 = points[3];

    for (double t = 0.0; t <= 1.0; t += 0.001) 
    {
        auto point = std::pow(1 - t, 3) * p_0 + 3 * t * std::pow(1 - t, 2) * p_1 +
                 3 * std::pow(t, 2) * (1 - t) * p_2 + std::pow(t, 3) * p_3;

        window.at<cv::Vec3b>(point.y, point.x)[2] = 255;
    }
}

inline cv::Point2f lerp(const float t, const cv::Point2f& x, const cv::Point2f y)
{
    return (1 - t) * x + t * y;
}

cv::Point2f recursive_bezier(const std::vector<cv::Point2f> &control_points, float t) 
{
    // TODO: Implement de Casteljau's algorithm
    if (control_points.size() == 1) {
        return control_points[0];
    }

    std::vector<cv::Point2f> sub_points;
    for (int i = 0; i < control_points.size()-1; ++i) {
        sub_points.push_back(lerp(t, control_points[i], control_points[i+1]));
    }
    return recursive_bezier(sub_points, t);
}

void bezier(const std::vector<cv::Point2f> &control_points, cv::Mat &window) 
{
    // TODO: Iterate through all t = 0 to t = 1 with small steps, and call de Casteljau's 
    // recursive Bezier algorithm.
    const float dt = 0.001;
    
    for (float t = 0; t <= 1; t += dt) {
        auto point = recursive_bezier(control_points, t);

        int dx = (point.x - floor(point.x) < 0.5)? -1 : 1;
        int dy = (point.y - floor(point.y) < 0.5)? -1 : 1;
        int x = point.x, y = point.y;
        std::vector<std::tuple<int, int>> pos = {{x, y}, {x+dx, y}, {x, y+dy}, {x+dx, y+dy}};
        for (auto [px, py] : pos) {
            double distance = sqrt((point.x-px-0.5)*(point.x-px-0.5) + (point.y-py-0.5)*(point.y-py-0.5));
            uchar color = 255.0 * (sqrt(2.0) - distance) / sqrt(2.0);
            window.at<cv::Vec3b>(py, px)[1] = std::max(color, window.at<cv::Vec3b>(py, px)[1]);
        }
    }
}

int main() 
{
    cv::Mat window = cv::Mat(700, 700, CV_8UC3, cv::Scalar(0));
    cv::cvtColor(window, window, cv::COLOR_BGR2RGB);
    cv::namedWindow("Bezier Curve", cv::WINDOW_AUTOSIZE);

    cv::setMouseCallback("Bezier Curve", mouse_handler, nullptr);

    int key = -1;
    while (key != 27) 
    {
        for (auto &point : control_points) 
        {
            cv::circle(window, point, 3, {255, 255, 255}, 3);
        }

        if (control_points.size() == 4) 
        {
            naive_bezier(control_points, window);
            bezier(control_points, window);

            cv::imshow("Bezier Curve", window);
            cv::imwrite("my_bezier_curve.png", window);
            key = cv::waitKey(0);

            return 0;
        }

        cv::imshow("Bezier Curve", window);
        key = cv::waitKey(20);
    }

return 0;
}
