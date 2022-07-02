#CC = icc 
CCFLAGS=-qmkl 
#MKL_PATH=/opt/intel/composer_xe_2013_sp1/mkl
#OMP_PATH=/opt/intel/composer_xe_2013_sp1/lib/intel64
# for dynamic linking with MKL
#MKL_LIB=-L${MKL_PATh}/lib/intel64 -lmkl_intel_lp64 -lmkl_intel_thread -lmkl_core  

# for static linking
#MKL_LIB=-Wl,--start-group $(MKL_PATH)/lib/intel64/libmkl_intel_lp64.a $(MKL_PATH)/lib/intel64/libmkl_intel_thread.a $(MKL_PATH)/lib/intel64/libmkl_core.a -Wl,--end-group 

dgemm : dgemm.c
	$(CC) $(CCFLAGS) $< -o dgemm
	
clean:
	rm dgemm







