find_path(liberParVisu_INCLUDE_DIRS liberParVisu.h /gpfs/home/bxk267/work/LL_Research/Libraries/LLParVisu/liberParVisu "$ENV{NAMER_ROOT}")

find_library(liberParVisu_LIBRARIES liberParVisu /gpfs/home/bxk267/work/LL_Research/Libraries/LLParVisu/liberParVisu "$ENV{NAMER_ROOT}")

set(liberParVisu_FOUND TRUE)
 
if (NOT liberParVisu_INCLUDE_DIRS)
  set(liberParVisu_FOUND FALSE)
endif (NOT liberParVisu_INCLUDE_DIRS)

if (NOT liberParVisu_LIBRARIES)
  set(liberParVisu_FOUND FALSE)
endif (NOT liberParVisu_LIBRARIES)
