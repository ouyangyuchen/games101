<!---
\begin{bmatrix}
 &  &  & \\
 &  &  & \\
 &  &  & \\
 &  &  &
\end{bmatrix} 
--->
----
# Canonical Cube to Screen
after projection transform, we get a "canonical" cube $[-1,1]^3$.
## What's Screen
- a 2D-array of pixels
- size of array: resolution
- typical kind of raster display

![[5_pixels.png|350]]
*pixels on the screen*

- pixels' indices $(x, y)$ are both integers in range \[0, width) and \[0, height)
- pixel at $(x,y)$, its center is $(x+0.5,y+0.5)$
## Scaling and Translation
we want to transform $[-1,1]^2$ to $[0,width]\times [0,height]$ (neglect z)
we have viewport transform matrix:
$$M_{viewport}=
\begin{bmatrix}
\frac{width}{2} & 0 & 0 & \frac{width}{2}\\
0 & \frac{height}{2} & 0 & \frac{height}{2}\\
0 & 0 & 1 & 0\\
0 & 0 & 0 & 1
\end{bmatrix} 
$$
----
# Rasterization
## Why Triangles?
- Most basic polygon
	- Break up with other polygons
- Unique properties
	- Guarantee to be planar (on the same plane)
	- Well defined [[#2D Sampling|interior]]
	- Well defined method for interpolating values at vertices over triangle (barycentric interpolation)
## 2D Sampling

![[5_triangle_sampling.png|250]]
*Rasterizaztion As 2D Sampling*

![[5_jaggies.png|250]]
*Aliasing*

Sample if each pixel center is internal
>Q: **How to judge a point is inside / outside the triangle?**
>
>A: **A point is inside the triangle $\Leftrightarrow$ 3 cross products vectors are all out of/into the screen plane**
>
>![[5_triangle_judge_internal.png|300]]
>
>3 cross products: $P_0P_1 \times P_0Q$, $P_1P_2 \times P_1Q$, $P_2P_0 \times P_2Q$ (keep 3 points in order)

### Improvements
unnecessary to check all pixels, check all points in the **bounding box**:
$$
(x_{min},y_{max})\quad \quad (x_{max}, y_{max})
$$
$$
(x_{min},y_{min}) \quad \quad (x_{max},y_{min})
$$
or **increment triangle traversal**: (especially when the triangle is slim in the diagonals)

![[5_incre_triangle_traversal.png|300]]

----
# Code: Rasterization
```
for (int x = 0; x < xmax; ++x)    // bounding box?
	for (int y = 0; y < ymax; ++y)    // bounding box?
		image[x][y] = inside(tri, x+0.5, y+0.5);
```