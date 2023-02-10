//
// Created by LEI XU on 4/27/19.
//

#ifndef RASTERIZER_TEXTURE_H
#define RASTERIZER_TEXTURE_H
#include "global.hpp"
#include <eigen3/Eigen/Eigen>
#include <opencv2/opencv.hpp>
class Texture{
private:
    cv::Mat image_data;

public:
    Texture(const std::string& name)
    {
        image_data = cv::imread(name);
        cv::cvtColor(image_data, image_data, cv::COLOR_RGB2BGR);
        width = image_data.cols;
        height = image_data.rows;
    }

    int width, height;

    Eigen::Vector3f getColor(float u, float v)
    {
        auto u_img = u * width;
        auto v_img = (1 - v) * height;
        auto color = image_data.at<cv::Vec3b>(v_img, u_img);
        return Eigen::Vector3f(color[0], color[1], color[2]);
    }

    Eigen::Vector3f getColorBilinear(float u, float v)
    {
        u *= width;
        v = (1-v) * height;
        int u_min = u, v_min = v;
        int u_max = std::min(u_min+1, width), v_max = std::min(v_min+1, height);
        float s = (u - u_min) / (u_max - u_min), t = (v - v_min) / (v_max - v_min);

        auto colors0 = image_data.at<cv::Vec3b>(v_min, u_min);
        auto colors1 = image_data.at<cv::Vec3b>(v_max, u_min);
        auto colors2 = image_data.at<cv::Vec3b>(v_min, u_max);
        auto colors3 = image_data.at<cv::Vec3b>(v_max, u_max);

        auto vec0 = Eigen::Vector3f(colors0[0], colors0[1], colors0[2]);
        auto vec1 = Eigen::Vector3f(colors1[0], colors1[1], colors1[2]);
        auto vec2 = Eigen::Vector3f(colors2[0], colors2[1], colors2[2]);
        auto vec3 = Eigen::Vector3f(colors3[0], colors3[1], colors3[2]);

        return lerp(t, lerp(s, vec0, vec1), lerp(s, vec2, vec3));
    }

    static Eigen::Vector3f lerp(const float alpha, const Eigen::Vector3f x, const Eigen::Vector3f y)
    {
        return alpha * y + (1.0 - alpha) * x;
    }
};
#endif //RASTERIZER_TEXTURE_H
