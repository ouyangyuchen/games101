<!---
\begin{bmatrix}
 &  &  & \\
 &  &  & \\
 &  &  & \\
 &  &  &
\end{bmatrix} 
--->
----
# View / Camera Transformation
## Setting the Camera
define the camera:
- camera **position** $\overrightarrow{e}$
- look-at / **gaze direction** $\overrightarrow{g}$
- **up-direction** $\overrightarrow{t}$

![[4_view_transform.png|300]]
![[4_view_transform2.png|300]]
always transform camera to:
- **the origin, up at Y, look-at -Z**
- **all objects along with**
## Transform Matrix
- Decomposing Transform
$$
M_{view}=R_{view}\cdot T_{view}
$$
- Translation to the origin
$$
T_{view}=
\begin{bmatrix}
1 &  &  & -x_e\\
 & 1 &  & -y_e\\
 &  & 1 & -z_e\\
 &  &  &1
\end{bmatrix} 
$$
- Rotate t to Y, g to -Z, (g$\times$t) to X
using property of orthogonal matrix:
$$
R_{view}^{-1}=
\begin{bmatrix}
x_{g\times t} & x_t & x_{-g} & 0\\
y_{g\times t} & y_t & y_{-g} & 0\\
z_{g\times t} & z_t & z_{-g} & 0\\
0 & 0 & 0 & 1
\end{bmatrix} 
\quad \Rightarrow \quad
R_{view} = 
\begin{bmatrix}
x_{g\times t} & y_{g\times t} & z_{g\times t} & 0\\
x_t & y_t & z_t & 0\\
x_{-g} & y_{-g} & z_{-g} & 0\\
0 & 0 & 0 & 1
\end{bmatrix} 
$$
----
# Projection
**from 3D to 2D**
![[4_projection.png|600]]
*perspective projection and orthographic projection*
## Orthographic Projection
![[4_ortho_projection.png]]
*orthographic projection*
$$
M_{ortho}=
\begin{bmatrix}
\frac{2}{r-l} &  &  & \\
 & \frac{2}{t-b} &  & \\
 &  & \frac{2}{n-f} & \\
 &  &  & 1
\end{bmatrix} 
\begin{bmatrix}
1 &  &  & -\frac{l+r}{2}\\
 & 1 &  & -\frac{t+b}{2}\\
 &  & 1 & -\frac{f+n}{2}\\
 &  &  &1
\end{bmatrix} 
$$
## Perspective Projection

![[4_perspective_proj.png|500]]
*perspective projection transform*
$$x'=\frac{nx}{z}\quad\quad y'=\frac{ny}{z}$$
using equality property of [[lec3-2_3D_Transformations#3D Homogeneous Coordinates|homogeneous coordinates]]:
$$
\begin{bmatrix}
x' \\
y' \\
z' \\
1 
\end{bmatrix} ==
\begin{bmatrix}
nx\\
ny\\
zz'(unknown)\\
z
\end{bmatrix} 
$$
define the perspective matrix (**n** for *near*, **f** for *far*, $0>n>f$):
$$
M_{persp\rightarrow ortho}=
\begin{bmatrix}
n & 0 & 0 & 0\\
0 & n & 0 & 0\\
0 & 0 & n+f & -nf\\
0 & 0 & 1 & 0
\end{bmatrix} 
$$
- Any point on the near plane will not change.
- Any point's z on the far plane will not change

next, do orthographic projection to print.
$$
M_{persp}=M_{ortho}M_{persp\rightarrow ortho}
$$
>**NOTE: The new z' is *NOT* equivalent to the original z. It is farer to origin.**
$$
z'=\frac{z(n+f)-nf}{z}=n+f-\frac{nf}{z}<z
$$

in perspective projection, use **field-of-view (fovY)** and **aspect ratio** to substitute *left, right, top, bottom*:
![[4_fovY_aspect_view.png|450]]

$$
tan\frac{fovY}{2}=\frac{t}{|n|}
\quad \quad \quad
aspect=\frac{right}{top}
$$