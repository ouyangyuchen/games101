----
# Aliasing
Rasterization is [[lec5_rasterization_1#2D Sampling|2D-sampling of an image]].

In frequency domain, the bandwidth of common images are usually **infinite**:

![[6_boy_freq.png|500]]
*image in spatial and frequency domain*

discrete sampling $\Rightarrow$ periodic in frequency domain $\Rightarrow$ high frequency will overlap ([Nyquist Sampling Theorum](https://en.wikipedia.org/wiki/Nyquist%E2%80%93Shannon_sampling_theorem)) $\Rightarrow$ low-pass system $\Rightarrow$ distortion occurs (aliasing!)
> **Increase sampling rate (resolution) can also reduce aliasing.**
----
# Antialiasing
## Antialiasing Sampling

![[6_anti_aliasing.png|600]]
*loss-pass pre-filtering, then sampling*

> **It doesn't work if sampling first then filtering.**
## Box Filter
If we use convolution, ideal **low-pass filter** is not feasible because of its infinite duration length.
We need Finite-Impulse-Response filter $\rightarrow$ Box Filter (size, shape..., recall *windows* in dsp)

![[6_box_filter.png|200]]
*box filter or convolution kernel*

![[6_box_freq_domain.png|200]]
*box filter in frequency domain*

- windows-length $\uparrow$ , main-lobe become slimmer
- box filter size $\uparrow$ , higher frequency $\downarrow$ , blur $\uparrow$
## Averaging Values in Pixel
Box filter is a useful low-pass system.
1. **convolve** `f(x,y)` by box filter blurring.     *low-pass filtering*
2. **sample** all pixels.     *frequency shift in periods, avoid aliasing*
### Computing Area to Pixel-Value
The average value of pixel `f(x,y` = the proportion of area covered by the triangle.

![[6_pixel_area_average.png|500]]
## SuperSampling
*Why it works?*
Super-sampling (increase sampling rate) $\Rightarrow$ less aliasing $\Rightarrow$ box filter (low-pass + downsampling) 
>**N is large, box-filter bandwidth will decrease, *information lost!*** 
>**N is small, box-filter bandwidth is large, high-frequency components are reserved. When downsampling, spectrum will be *more overlapped*.**

1. Take N\*N samples "inside" each pixel.
![[6_super_samp.png|400]]
3. Average the N\*N samples every pixel.
![[6_average.png|400]]

*What's cost?*
Exchange computing efficiency for less distortion.

----
# Antialiasing Today
- FXAA (Fast Approximate AA)
- TAA (Temporal AA)
- Super resolution: DLSS (Deep Learning Super Sampling)