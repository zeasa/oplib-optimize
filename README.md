# oplib-optimize

this library include 3 deep learning operator inplementations, including conv2D,relu and pooling, single layer as while as fused version.

1.env needed

```
a.ubuntu18.04.5 with gcc 7.5.0
b.cmake 3.10.2 or above
c.intel oneMKL 2022.1.0
```

2.how to build

```
cd oplib-optimize
mkdir -p build
cd build
cmake ..
make -j
```

3.run test

```
cd oplib-optimize
cd build
ctest -V
```

4.how to run

```
cd oplib-optimize
cd build/example
./benchmark_net_conv2d_relu_pooling_nofuse -d
./benchmark_net_conv2d_relu_pooling_fuse -d
```

then can get the benchmark report with in the console like this:

```
[DEBUG]: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
[DEBUG]: dump mode = [false]
[DEBUG]: peak avx2 vmul+vadd computation performance(1 thread) is [36.693602] GFLOPS/s
[DEBUG]: peak fpu computation performance(1 thread) is [4.584952] GFLOPS/s
[DEBUG]: allocate buffers for input/output/intermediate tensors!
[DEBUG]: generate test data for [pbuf_ifm_conv]
[DEBUG]: generate test data for [pbuf_wt_conv]
[DEBUG]: generate test data for [pbuf_bs_conv]
[DEBUG]: oplib_layer_conv2d_s1 param : IN=[4],IH=[512],IW=[512],IC=[32],KW=[3],KH=[3],OC=[16],gflops=[9.663676]
[DEBUG]: oplib_layer_relu param : IN=[4],IH=[512],IW=[512],IC=[16],OH=[512],OW=[512],OC=[16],gflops=[0.016777]
[DEBUG]: oplib_layer_avgpool param : IN=[4],IH=[512],IW=[512],IC=[16],OH=[256],OW=[256],OC=[16],gflops=[0.016777]
[DEBUG]: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
[DEBUG]: report : oplib_layer_conv2d_s1     cost [7.991605] seconds in avg within [1] iters
[DEBUG]: report : oplib_layer_relu          cost [0.009072] seconds in avg within [200] iters
[DEBUG]: report : oplib_layer_avgpool       cost [0.033691] seconds in avg within [200] iters
[DEBUG]: report : oplib_layer_conv2d_s1_omp cost [1.044546] seconds in avg within [1] iters
[DEBUG]: report : oplib_layer_relu_omp      cost [0.006228] seconds in avg within [200] iters
[DEBUG]: report : oplib_layer_avgpool_omp   cost [0.004644] seconds in avg within [200] iters
[DEBUG]: report : oplib_layer_conv2d_s1     calculation profermance is [1.209229] GFLOPS/s
[DEBUG]: report : oplib_layer_relu          calculation profermance is [1.849413] GFLOPS/s
[DEBUG]: report : oplib_layer_avgpool       calculation profermance is [0.497979] GFLOPS/s
[DEBUG]: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
```

notice: the '-d' option will print the input and output tensor contents with in the console

5.more about

this code library uses openmp feature of gcc to optimize the execute speed of the program.
