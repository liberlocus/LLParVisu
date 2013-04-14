find_path(parliber_INCLUDE_DIRS liberParOut.h /gpfs/home/bxk267/work/LL_Research/Libraries/LLParVisu/parliber "$ENV{NAMER_ROOT}")

find_library(parliber_LIBRARIES parliber /gpfs/home/bxk267/work/LL_Research/Libraries/LLParVisu/parliber "$ENV{NAMER_ROOT}")

set(parliber_FOUND TRUE)
 
if (NOT parliber_INCLUDE_DIRS)
  set(parliber_FOUND FALSE)
endif (NOT parliber_INCLUDE_DIRS)

if (NOT parliber_LIBRARIES)
  set(parliber_FOUND FALSE)
endif (NOT parliber_LIBRARIES)
