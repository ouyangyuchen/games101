<!---
\begin{bmatrix}
 &  &  & \\
 &  &  & \\
 &  &  & \\
 &  &  &
\end{bmatrix} 
--->
----
# 3D Homogeneous Coordinates
make an analogy to [[lec3_2D_Transformation#Homogeneous Coordinates|Homogeneous Coordinates in 2D]].
- 3D-vector = $(x, y, z, 0)^T$
- 3D-point = $(x,y,z,1)^T$.
$$(x,y,z,w)^T=(\frac{x}{w},\frac{y}{w},\frac{z}{w},1)^T \hspace{1cm} w\neq0$$
*same 3d-point in different expressions*

----
# 3D Transform Matrices
$$M=
\begin{bmatrix}
a & b & c & t_x\\
d & e & f & t_y\\
h & i & j & t_z\\
0 & 0 & 0 & 1
\end{bmatrix} 
$$
>**Rotate First, Translation second!!!**
## Scaling Matrix
$$S(s_x,s_y,s_z)=
\begin{bmatrix}
s_x &  &  & \\
 & s_y &  & \\
 &  & s_z & \\
 &  &  &1
\end{bmatrix} 
$$
## Translation Matrix
$$T(t_x,t_y,t_z)=
\begin{bmatrix}
1 &  &  & t_x\\
 & 1 &  & t_y\\
 &  & 1 & t_z\\
 &  &  &1
\end{bmatrix}
$$
## Rotation Matrices
rotate in 3 various axis ($\alpha$ is angle in counterclockwise):
$$R_x(\alpha)=
\begin{bmatrix}
1 & 0 & 0 & 0\\
0 & cos\alpha & -sin\alpha & 0\\
0 & sin\alpha & cos\alpha & 0\\
0 & 0 & 0 & 1
\end{bmatrix} 
$$
$$
R_y(\alpha)=
\begin{bmatrix}
cos\alpha & 0 & sin\alpha & 0\\
0 & 1 & 0 & 0\\
-sin\alpha & 0 & cos\alpha & 0\\
0 & 0 & 0 &1
\end{bmatrix} 
$$
$$
R_z(\alpha)=
\begin{bmatrix}
cos\alpha & -sin\alpha & 0 & 0\\
sin\alpha & cos\alpha & 0 & 0\\
0 & 0 & 1 & 0\\
0 & 0 & 0 & 1
\end{bmatrix} 
$$
![[3_2_rotate_3d.png|300]]
*rotation in 3-dimension*

----
# 3D Rotations
## Decomposing
compose any 3d-rotation from $R_x$ $R_y$ $R_z$ :
$$
R_{xyz}(\alpha,\beta,\gamma)=R_x(\alpha)\cdot R_y(\beta)\cdot R_z(\gamma)
$$
## Rodrigue's Rotation Formula
Rotation by angle $\alpha$ around axis $\overrightarrow{n}$ ($||\overrightarrow{n}||=1$):
$$
R(\overrightarrow{n},\alpha)=cos(\alpha)+(1-cos(\alpha))nn^T+sin(\alpha)
\begin{bmatrix}
0 & -n_z & n_y\\
n_z & 0 & -n_x\\
-n_y & n_x & 0
\end{bmatrix} 
$$
### Extra: Cross Product in Matrix form
$$
\overrightarrow{a}\times\overrightarrow{b}=A^*b=\begin{bmatrix}
0 & -z_a & y_a\\
z_a & 0 & -x_a\\
-y_a & x_a & 0\\  
\end{bmatrix} 
\begin{bmatrix}
x_b\\
y_b\\
z_b
\end{bmatrix} 
$$