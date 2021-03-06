/**
 * @file    parallel_sort.h
 * @author  Patrick Flick <patrick.flick@gmail.com>
 * @brief   Declares the parallel sorting function.
 *
 * Copyright (c) 2014 Georgia Institute of Technology. All Rights Reserved.
 */

#ifndef PARALLEL_SORT_H
#define PARALLEL_SORT_H

#include <mpi.h>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdlib>

/**
 * @brief   Parallel, distributed sorting over all processors in `comm`. Each
 *          processor has the local input [begin, end).
 *
 * Note that `end` is given one element beyond the input. This corresponds to
 * the API of C++ std::sort! You can get the size of the local input with:
 * int local_size = end - begin;
 *
 * @param begin Pointer to the first element in the input sequence.
 * @param end   Pointer to one element past the input sequence. Don't access this!
 * @param comm  The MPI communicator with the processors participating in the
 *              sorting.
 */
void parallel_sort(int* begin, int* end, MPI_Comm comm);


/*********************************************************************
 *              Declare your own helper functions here               *
 *********************************************************************/

// ...
int partition(int* begin, int local_size, int pivot);

int compute_size(int* new_size, int cutpoint, int small_sum, int large_sum, MPI_Comm comm);

int compute_counts(int* sendcnts, int* recvcnts, int cutpoint, int* small_size, int* local_size, int* new_size, MPI_Comm comm);

int compute_displs(int* sdispls, int* rdispls, int* sendcnts, int* recvcnts, MPI_Comm comm);

#endif // PARALLEL_SORT_H
