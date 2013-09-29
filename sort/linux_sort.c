#include <stdio.h>
#define u32 unsigned int

static void u32_swap(void *a, void *b, int size)
{
        u32 t = *(u32 *)a;
        *(u32 *)a = *(u32 *)b;
        *(u32 *)b = t;
}

static void generic_swap(void *a, void *b, int size)
{
        char t;

        do {
                t = *(char *)a;
                *(char *)a++ = *(char *)b;
                *(char *)b++ = t;
        } while (--size > 0);
}


/**
 * sort - sort an array of elements
 * @base: pointer to data to sort
 * @num: number of elements
 * @size: size of each element
 * @cmp_func: pointer to comparison function
 * @swap_func: pointer to swap function or NULL
 *
 * This function does a heapsort on the given array. You may provide a
 * swap_func function optimized to your element type.
 *
 * Sorting time is O(n log n) both on average and worst-case. While
 * qsort is about 20% faster on average, it suffers from exploitable
 * O(n*n) worst-case behavior and extra memory requirements that make
 * it less suitable for kernel use.
 */

void sort(void *base, size_t num, size_t size,
          int (*cmp_func)(const void *, const void *),
          void (*swap_func)(void *, void *, int size))
{
        /* pre-scale counters for performance */
        int i = (num/2 - 1) * size, n = num * size, c, r;

        if (!swap_func)
                swap_func = (size == 4 ? u32_swap : generic_swap);

        /* heapify */
        for ( ; i >= 0; i -= size) {
                for (r = i; r * 2 + size < n; r  = c) {
                        c = r * 2 + size;
                        if (c < n - size &&
                                        cmp_func(base + c, base + c + size) < 0)
                                c += size;
                        if (cmp_func(base + r, base + c) >= 0)
                                break;
                        swap_func(base + r, base + c, size);
                }
        }

        /* sort */
        for (i = n - size; i > 0; i -= size) {
                swap_func(base, base + i, size);
                for (r = 0; r * 2 + size < i; r = c) {
                        c = r * 2 + size;
                        if (c < i - size &&
                                        cmp_func(base + c, base + c + size) < 0)
                                c += size;
                        if (cmp_func(base + r, base + c) >= 0)
                                break;
                        swap_func(base + r, base + c, size);
                }
        }
}

int array[5] = {2,1,3,4,0};
int cmp_func_int(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
	return -1;
}


int main(int argc,char **argv)
{
	sort(array,sizeof(array)/sizeof(int),sizeof(int),cmp_func_int,NULL);
	printf("%d %d %d %d %d\r\n",array[0],array[1],array[2],array[3],array[4]);

}
