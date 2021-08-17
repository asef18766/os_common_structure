#include <stdio.h>
#include <windows.h>
#define MAX_THREADS 2

bool flag[MAX_THREADS] = {false}; // flag for checking who wants to enter C.S.

DWORD WINAPI ChildThreadFunction(LPVOID lpParam)
{
    DWORD id = *((DWORD *)lpParam);
    flag[id] = true;

    printf_s("thread %d is going to waiting ...\n", id);

    while (flag[1 - id]) // check if others wants to enter C.S.
        ;                // here does busy waiting
    // critical section
    printf_s("thread %d is going to critical sections\n", id);

    // leaving critial section
    printf_s("thread %d is going to leave ...\n", id);
    flag[id] = false;
    return 0;
}
int main(int argc, char const *argv[])
{
    DWORD dwDataArray[MAX_THREADS];
    DWORD dwThreadIdArray[MAX_THREADS];
    HANDLE hThreadArray[MAX_THREADS];

    for (int i = 0; i != MAX_THREADS; ++i)
    {
        dwDataArray[i] = i;
        hThreadArray[i] = CreateThread(NULL,                 // default security attributes
                                       0,                    // use default stack size
                                       ChildThreadFunction,  // thread function name
                                       &dwDataArray[i],      // argument to thread function
                                       0,                    // use default creation flags
                                       &dwThreadIdArray[i]); // returns the thread identifier

        if (hThreadArray[i] == NULL)
        {
            perror("[thread create failure]");
            ExitProcess(3);
        }
    }
    WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);

    for (int i = 0; i != MAX_THREADS; ++i)
        CloseHandle(hThreadArray[i]);
    return 0;
}
