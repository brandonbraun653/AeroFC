Temporary place to jot down some notes before a proper install document.

1. On Linux, need to get latest version of GCC (9) and set as default: http://tuxamito.com/wiki/index.php/Installing_newer_GCC_versions_in_Ubuntu
    Otherwise threading won't compile properly.
2. Need to install g++ development sources for the the FreeRTOS Posix port: sudo apt install g++-multilib libc6-dev-i386
3. Recompile boost thread/chrono/date_time libraries using toolset=gcc-9
4. Export LD_LIBRARY_PATH=<path-to-boost>/stage/lib so that we can find the shared libraries.