#include "dataGenerator.h"
#include <sys/resource.h>
#include <cstring>
#include <list>

#define EXIT_SUCCESS 0
#define SMALL_ARRAY_SIZE 10
#define MEDIUM_ARRAY_SIZE 1000
#define LARGE_ARRAY_SIZE 100000
#define numOfIteration 30
extern int option;
extern std::list<Chunk> allocated, freed;

using std::cout;
using std::endl;
using std::string;

/*i will have a loop to run each strategy 30 times
to calculate the average time consumption and 
compare the time for each allocation strategy */

int main(int argc, char **argv)
{

    if (argc == 1)
        option = FF;
    else
    {
        if (strcmp(argv[1], "BF") == 0)
            option = BF;
        else if (strcmp(argv[1], "WF") == 0)
            option = WF;
        else if (strcmp(argv[1], "FF") == 0)
        {
            option = FF;
        }
        else
        {
            cout << "***INVALID COMMAND***" << endl;
            cout << "./main FF or ./main for first fit" << endl;
            cout << "./main BF for best fit" << endl;
            cout << "./main WF for worst fit" << endl;
            cout << "Please check README.md file" << endl;
            exit(0);
        }
    }

    // Small Arrays
    cout << "\n---------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for small array of integers\n";
    cout << "---------------------------------------------------------------\n";
    int *sip1 = (int *)intArray(SMALL_ARRAY_SIZE * 3);
    int *sip2 = (int *)intArray(SMALL_ARRAY_SIZE * 2);
    int *sip3 = (int *)arrayOfOddIntegers(SMALL_ARRAY_SIZE * 4);
    int *sip4 = (int *)intArray(SMALL_ARRAY_SIZE * 5);
    showStatus();
    dealloc(sip2);
    dealloc(sip4);
    dealloc(sip1);
    showStatus();
    int *sip5 = (int *)intArray(SMALL_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usagesi;
    struct rusage r_usagesi;
    getrusage(RUSAGE_SELF, &usagesi);
    getrusage(RUSAGE_SELF, &r_usagesi);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usagesi.ru_maxrss << endl;
    cout << "System time consumed: " << usagesi.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usagesi.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(sip3);
    dealloc(sip5);
    allocated.clear();
    freed.clear();

    cout << "\n------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for small array of doubles\n";
    cout << "------------------------------------------------------------\n";
    double *sdp1 = (double *)doubleArray(SMALL_ARRAY_SIZE * 3);
    double *sdp2 = (double *)doubleArray(SMALL_ARRAY_SIZE * 2);
    double *sdp3 = (double *)doubleArray(SMALL_ARRAY_SIZE * 4);
    double *sdp4 = (double *)doubleArray(SMALL_ARRAY_SIZE * 5);
    showStatus();
    dealloc(sdp2);
    dealloc(sdp4);
    dealloc(sdp1);
    showStatus();
    double *sdp5 = (double *)doubleArray(SMALL_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usagesd;
    struct rusage r_usagesd;
    getrusage(RUSAGE_SELF, &usagesd);
    getrusage(RUSAGE_SELF, &r_usagesd);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usagesd.ru_maxrss << endl;
    cout << "System time consumed: " << usagesd.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usagesd.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(sdp3);
    dealloc(sdp5);
    allocated.clear();
    freed.clear();

    cout << "\n--------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for small array of characters\n";
    cout << "--------------------------------------------------------------\n";
    char *scp1 = (char *)charArray(SMALL_ARRAY_SIZE * 3);
    char *scp2 = (char *)charArray(SMALL_ARRAY_SIZE * 2);
    char *scp3 = (char *)charArray(SMALL_ARRAY_SIZE * 4);
    char *scp4 = (char *)charArray(SMALL_ARRAY_SIZE * 5);
    showStatus();
    dealloc(scp2);
    dealloc(scp4);
    dealloc(scp1);
    showStatus();
    char *scp5 = (char *)charArray(SMALL_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usagesc;
    struct rusage r_usagesc;
    getrusage(RUSAGE_SELF, &usagesc);
    getrusage(RUSAGE_SELF, &r_usagesc);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usagesc.ru_maxrss << endl;
    cout << "System time consumed: " << usagesc.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usagesc.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(scp3);
    dealloc(scp5);
    allocated.clear();
    freed.clear();

    cout << "\n------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for small array of floats\n";
    cout << "------------------------------------------------------------\n";
    float *sfp1 = (float *)floatArray(SMALL_ARRAY_SIZE * 3);
    float *sfp2 = (float *)floatArray(SMALL_ARRAY_SIZE * 2);
    float *sfp3 = (float *)floatArray(SMALL_ARRAY_SIZE * 4);
    float *sfp4 = (float *)floatArray(SMALL_ARRAY_SIZE * 5);
    showStatus();
    dealloc(sfp2);
    dealloc(sfp4);
    dealloc(sfp1);
    showStatus();
    float *sfp5 = (float *)floatArray(SMALL_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usagesf;
    struct rusage r_usagesf;
    getrusage(RUSAGE_SELF, &usagesf);
    getrusage(RUSAGE_SELF, &r_usagesf);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usagesf.ru_maxrss << endl;
    cout << "System time consumed: " << usagesf.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usagesf.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(sfp3);
    dealloc(sfp5);
    allocated.clear();
    freed.clear();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for small array of different data types\n";
    cout << "----------------------------------------------------------------------\n";
    float *sfp11 = (float *)floatArray(SMALL_ARRAY_SIZE * 3);
    double *sdp11 = (double *)doubleArray(SMALL_ARRAY_SIZE * 2);
    char *scp11 = (char *)charArray(SMALL_ARRAY_SIZE * 4);
    int *sip11 = (int *)intArray(SMALL_ARRAY_SIZE * 5);
    showStatus();
    dealloc(sdp11);
    dealloc(sip11);
    dealloc(sfp11);
    showStatus();
    float *sfp21 = (float *)floatArray(SMALL_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usage11;
    struct rusage r_usage11;
    getrusage(RUSAGE_SELF, &usage11);
    getrusage(RUSAGE_SELF, &r_usage11);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usage11.ru_maxrss << endl;
    cout << "System time consumed: " << usage11.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usage11.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(scp11);
    dealloc(sfp21);
    allocated.clear();
    freed.clear();

    // Medium Arrays
    cout << "\n-----------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for medium array of integers\n";
    cout << "-----------------------------------------------------------------\n";
    int *mip1 = (int *)intArray(MEDIUM_ARRAY_SIZE * 3);
    int *mip2 = (int *)intArray(MEDIUM_ARRAY_SIZE * 2);
    int *mip3 = (int *)arrayOfOddIntegers(MEDIUM_ARRAY_SIZE * 4);
    int *mip4 = (int *)intArray(MEDIUM_ARRAY_SIZE * 5);
    showStatus();
    dealloc(mip2);
    dealloc(mip4);
    dealloc(mip1);
    showStatus();
    int *mip5 = (int *)intArray(MEDIUM_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usagemi;
    struct rusage r_usagemi;
    getrusage(RUSAGE_SELF, &usagemi);
    getrusage(RUSAGE_SELF, &r_usagemi);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usagemi.ru_maxrss << endl;
    cout << "System time consumed: " << usagemi.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usagemi.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(mip3);
    dealloc(mip5);
    allocated.clear();
    freed.clear();

    cout << "\n--------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for medium array of doubles\n";
    cout << "--------------------------------------------------------------\n";
    double *mdp1 = (double *)doubleArray(MEDIUM_ARRAY_SIZE * 3);
    double *mdp2 = (double *)doubleArray(MEDIUM_ARRAY_SIZE * 2);
    double *mdp3 = (double *)doubleArray(MEDIUM_ARRAY_SIZE * 4);
    double *mdp4 = (double *)doubleArray(MEDIUM_ARRAY_SIZE * 5);
    showStatus();
    dealloc(mdp2);
    dealloc(mdp4);
    dealloc(mdp1);
    showStatus();
    double *mdp5 = (double *)doubleArray(MEDIUM_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usagemd;
    struct rusage r_usagemd;
    getrusage(RUSAGE_SELF, &usagemd);
    getrusage(RUSAGE_SELF, &r_usagemd);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usagemd.ru_maxrss << endl;
    cout << "System time consumed: " << usagemd.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usagemd.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(mdp3);
    dealloc(mdp5);
    allocated.clear();
    freed.clear();

    cout << "\n-------------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for medium array of characters\n";
    cout << "-------------------------------------------------------------------\n";
    char *mcp1 = (char *)charArray(MEDIUM_ARRAY_SIZE * 3);
    char *mcp2 = (char *)charArray(MEDIUM_ARRAY_SIZE * 2);
    char *mcp3 = (char *)charArray(MEDIUM_ARRAY_SIZE * 4);
    char *mcp4 = (char *)charArray(MEDIUM_ARRAY_SIZE * 5);
    showStatus();
    dealloc(mcp2);
    dealloc(mcp4);
    dealloc(mcp1);
    showStatus();
    char *mcp5 = (char *)charArray(MEDIUM_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usagemc;
    struct rusage r_usagemc;
    getrusage(RUSAGE_SELF, &usagemc);
    getrusage(RUSAGE_SELF, &r_usagemc);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usagemc.ru_maxrss << endl;
    cout << "System time consumed: " << usagemc.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usagemc.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(mcp3);
    dealloc(mcp5);
    allocated.clear();
    freed.clear();

    cout << "\n---------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for medium array of floats\n";
    cout << "--------------------------------------------------------------\n";
    float *mfp1 = (float *)floatArray(MEDIUM_ARRAY_SIZE * 3);
    float *mfp2 = (float *)floatArray(MEDIUM_ARRAY_SIZE * 2);
    float *mfp3 = (float *)floatArray(MEDIUM_ARRAY_SIZE * 4);
    float *mfp4 = (float *)floatArray(MEDIUM_ARRAY_SIZE * 5);
    showStatus();
    dealloc(mfp2);
    dealloc(mfp4);
    dealloc(mfp1);
    showStatus();
    float *mfp5 = (float *)floatArray(MEDIUM_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usagemf;
    struct rusage r_usagemf;
    getrusage(RUSAGE_SELF, &usagemf);
    getrusage(RUSAGE_SELF, &r_usagemf);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usagemf.ru_maxrss << endl;
    cout << "System time consumed: " << usagemf.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usagemf.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(mfp3);
    dealloc(mfp5);
    allocated.clear();
    freed.clear();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for medium array of different data types\n";
    cout << "----------------------------------------------------------------------\n";
    float *sfp10 = (float *)floatArray(MEDIUM_ARRAY_SIZE * 3);
    double *sdp10 = (double *)doubleArray(MEDIUM_ARRAY_SIZE * 2);
    char *scp10 = (char *)charArray(MEDIUM_ARRAY_SIZE * 4);
    int *sip10 = (int *)intArray(MEDIUM_ARRAY_SIZE * 5);
    showStatus();
    dealloc(sdp10);
    dealloc(sip10);
    dealloc(sfp10);
    showStatus();
    float *sfp20 = (float *)floatArray(MEDIUM_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usage10;
    struct rusage r_usage10;
    getrusage(RUSAGE_SELF, &usage10);
    getrusage(RUSAGE_SELF, &r_usage10);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usage10.ru_maxrss << endl;
    cout << "System time consumed: " << usage10.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usage10.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(scp10);
    dealloc(sfp20);
    allocated.clear();
    freed.clear();

    // Large Arrays
    cout << "\n--------------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for large array of integers\n";
    cout << "--------------------------------------------------------------------\n";
    int *lip1 = (int *)intArray(LARGE_ARRAY_SIZE * 3);
    int *lip2 = (int *)intArray(MEDIUM_ARRAY_SIZE * 2);
    int *lip3 = (int *)arrayOfOddIntegers(LARGE_ARRAY_SIZE * 4);
    int *lip4 = (int *)intArray(LARGE_ARRAY_SIZE * 5);
    showStatus();
    dealloc(lip2);
    dealloc(lip4);
    dealloc(lip1);
    showStatus();
    int *lip5 = (int *)intArray(LARGE_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usageli;
    struct rusage r_usageli;
    getrusage(RUSAGE_SELF, &usageli);
    getrusage(RUSAGE_SELF, &r_usageli);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usageli.ru_maxrss << endl;
    cout << "System time consumed: " << usageli.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usageli.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(lip3);
    dealloc(lip5);
    allocated.clear();
    freed.clear();

    cout << "\n-----------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for large array of doubles\n";
    cout << "-----------------------------------------------------------------\n";
    double *ldp1 = (double *)doubleArray(LARGE_ARRAY_SIZE * 3);
    double *ldp2 = (double *)doubleArray(LARGE_ARRAY_SIZE * 2);
    double *ldp3 = (double *)doubleArray(LARGE_ARRAY_SIZE * 4);
    double *ldp4 = (double *)doubleArray(LARGE_ARRAY_SIZE * 5);
    showStatus();
    dealloc(ldp2);
    dealloc(ldp4);
    dealloc(ldp1);
    showStatus();
    double *ldp5 = (double *)doubleArray(LARGE_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usageld;
    struct rusage r_usageld;
    getrusage(RUSAGE_SELF, &usageld);
    getrusage(RUSAGE_SELF, &r_usageld);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usageld.ru_maxrss << endl;
    cout << "System time consumed: " << usageld.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usageld.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(ldp3);
    dealloc(ldp5);
    allocated.clear();
    freed.clear();

    cout << "\n---------------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for large array of characters\n";
    cout << "---------------------------------------------------------------------\n";
    char *lcp1 = (char *)charArray(LARGE_ARRAY_SIZE * 3);
    char *lcp2 = (char *)charArray(LARGE_ARRAY_SIZE * 2);
    char *lcp3 = (char *)charArray(LARGE_ARRAY_SIZE * 4);
    char *lcp4 = (char *)charArray(LARGE_ARRAY_SIZE * 5);
    showStatus();
    dealloc(lcp2);
    dealloc(lcp4);
    dealloc(lcp1);
    showStatus();
    char *lcp5 = (char *)charArray(LARGE_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usagelc;
    struct rusage r_usagelc;
    getrusage(RUSAGE_SELF, &usagelc);
    getrusage(RUSAGE_SELF, &r_usagelc);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usagelc.ru_maxrss << endl;
    cout << "System time consumed: " << usagelc.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usagelc.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(lcp3);
    dealloc(lcp5);
    allocated.clear();
    freed.clear();

    cout << "\n---------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for large array of floats\n";
    cout << "---------------------------------------------------------------\n";
    float *lfp1 = (float *)floatArray(LARGE_ARRAY_SIZE * 3);
    float *lfp2 = (float *)floatArray(LARGE_ARRAY_SIZE * 2);
    float *lfp3 = (float *)floatArray(LARGE_ARRAY_SIZE * 4);
    float *lfp4 = (float *)floatArray(LARGE_ARRAY_SIZE * 5);
    showStatus();
    dealloc(lfp2);
    dealloc(lfp4);
    dealloc(lfp1);
    showStatus();
    float *lfp5 = (float *)floatArray(LARGE_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usagelf;
    struct rusage r_usagelf;
    getrusage(RUSAGE_SELF, &usagelf);
    getrusage(RUSAGE_SELF, &r_usagelf);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usagelf.ru_maxrss << endl;
    cout << "System time consumed: " << usagelf.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usagelf.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(lfp3);
    dealloc(lfp5);
    allocated.clear();
    freed.clear();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "Allocation and Deallocation for large array of different data types\n";
    cout << "----------------------------------------------------------------------\n";
    float *sfp12 = (float *)floatArray(LARGE_ARRAY_SIZE * 3);
    double *sdp12 = (double *)doubleArray(LARGE_ARRAY_SIZE * 2);
    char *scp12 = (char *)charArray(LARGE_ARRAY_SIZE * 4);
    int *sip12 = (int *)intArray(LARGE_ARRAY_SIZE * 5);
    showStatus();
    dealloc(sdp12);
    dealloc(sip12);
    dealloc(sfp12);
    showStatus();
    float *sfp22 = (float *)floatArray(LARGE_ARRAY_SIZE * 3);
    showStatus();

    struct rusage usage12;
    struct rusage r_usage12;
    getrusage(RUSAGE_SELF, &usage12);
    getrusage(RUSAGE_SELF, &r_usage12);
    cout << "\n**********Memory and Time consumption**********\n";
    cout << "Memory consumed: " << r_usage12.ru_maxrss << endl;
    cout << "System time consumed: " << usage12.ru_stime.tv_usec << " microseconds" << endl;
    cout << "User time consumed: " << usage12.ru_utime.tv_usec << " microseconds" << endl;
    dealloc(scp12);
    dealloc(sfp22);
    allocated.clear();
    freed.clear();

    return EXIT_SUCCESS;
}
