#source /opt/intel/compilers_and_libraries_2018/linux/mkl/bin/mklvars.sh intel64
# for dynamic linking with MKL
#CFLAGS=-I${MKL_INC} -L${MKL_LIB} -Wl,--start-group -lmkl_intel_lp64 -lmkl_intel_thread -lmkl_core -Wl,--end-group -openmp -lpthread 
MKLROOT=/opt/intel/compilers_and_libraries_2018/linux/mkl
IOMP5_PATH =/opt/intel/compilers_and_libraries_2018/linux/lib/intel64
#/root/GEMM/mklml_lnx_2018.0.2.20171115
MKL_LIB=$(MKLROOT)/lib/intel64

#/opt/intel/mkl/lib/intel64
# for static linking
mkl= -I$(MKLROOT)/include -Wl,--start-group $(MKL_LIB)/libmkl_intel_lp64.a $(MKL_LIB)/libmkl_intel_thread.a $(MKL_LIB)/libmkl_core.a -Wl,--end-group -L$(IOMP5_PATH) -liomp5 -ldl -lpthread 

#mkl=-I$(MKLROOT)/include -L$(MKLROOT)/lib/ -lmklml_intel  -liomp5 -ldl -lpthread
all: sgemm_cblas  sgemm_cblas_ALIGN sgemm_cblas_ALIGN_LD 
#xtest : sgemm.c
#	icc $< -o xtest ${mkl} 

#export KMP_AFFINITY=granularity=fine,compact,1,0
#icc -o sgemm sgemm.c -mkl -std=c99
#gcc -o sgemm-blas-hsw sgemm-blas.c -I ~/OpenBLAS-sandybridge ~/OpenBLAS-sandybridge/libopenblas.a -lpthread -L ~/OpenBLAS-sandybridge
#gcc -o sgemm-openblas sgemm-blas.c -I /root/openblas/OpenBLAS /root/openblas/OpenBLAS/libopenblas.a -lpthread -L /root/openblas/OpenBLAS
#
#static
sgemm_cblas: sgemm_cblas.cpp
	gcc $< -o $@ ${mkl} 
	
sgemm_cblas_ALIGN: sgemm_cblas.cpp
	gcc $< -o $@ ${mkl} -DMKL_ALIGN
sgemm_cblas_ALIGN_LD: sgemm_cblas.cpp
	gcc $< -o $@ ${mkl} -DMKL_ALIGN -DMKL_LD
#open_sgemm: sgemmbench.cpp
#	gcc $< -o $@ ../OpenBLAS-0.2.19/libopenblas.a -lpthread 
#icc -o sgemm-static -g -O3 sgemm-static.c -std=c99 -Wl,--start-group /opt/intel/mkl/lib/intel64/libmkl_intel_lp64.a /opt/intel/lib/intel64/libiomp5.a /opt/intel/mkl/lib/intel64/libmkl_core.a /opt/intel/mkl/lib/intel64/libmkl_intel_thread.a --end-group -lpthread

clean:
	rm sgemm_cblas sgemm_cblas_ALIGN sgemm_cblas_ALIGN_LD
	


