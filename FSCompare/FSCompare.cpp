#include <iostream>
#include <string>

#ifdef __cpp_lib_filesystem
    #include <filesystem>
    namespace fs = std::filesystem;
#elif __cpp_lib_experimental_filesystem
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
    #include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
#else
    #error "no filesystem support ='("
#endif

int main()
{
   
    fs::path RootDir;
    fs::path ExpectedPath;
    std::string sFileName = "/FileSubDir/FileName.ext"; //We have this path from somewhere.
#if defined(_WIN32)
   RootDir=fs::path(R"(D:\FooDir\BarDir\SubDir\ChildDir)");
   ExpectedPath = fs::path(R"(D:\FooDir\BarDir\SubDir\FileSubDir\FileName.ext)");
#else
   RootDir=fs::path(R"(/FooDir/BarDir/SubDir/ChildDir)");
   ExpectedPath = fs::path(R"(/FooDir/BarDir/SubDir/FileSubDir/FileName.ext)");
#endif
   

    fs::path pFilePath = RootDir.parent_path(); //We need "D:\FooDir\BarDir\SubDir\"
    pFilePath/=sFileName;
    if(pFilePath!=ExpectedPath)
    {
#if _WIN32
        std::cout << CFGName;
#endif
        std::cout <<":[ERROR]. Received:(" << pFilePath << ")." << std::endl;
    }
    else
    {
#if _WIN32
        std::cout << CFGName;
#endif
        std::cout <<":[OK]"<<std::endl;
    }

    return 0;
}

/*
 *OUTPUTS:
   v141_cpp14_Release:[OK]
   v141_cpp14_Release:[OK]
   v141_cpp20_Release:[ERROR]. Received:("D:/FileSubDir/FileName.ext").
   v141_cpp20_Release:[ERROR]. Received:("D:/FileSubDir/FileName.ext").
   v141_cpp17_Release:[ERROR]. Received:("D:/FileSubDir/FileName.ext").
   v141_cpp17_Release:[ERROR]. Received:("D:/FileSubDir/FileName.ext").
   LLVM_cpp20_Release:[ERROR]. Received:("D:/FileSubDir/FileName.ext").
   LLVM_cpp20_Release:[ERROR]. Received:("D:/FileSubDir/FileName.ext").
   LLVM_cpp17_Release:[ERROR]. Received:("D:/FileSubDir/FileName.ext").
   LLVM_cpp17_Release:[ERROR]. Received:("D:/FileSubDir/FileName.ext").
   LLVM_cpp14_Release:[OK]
   LLVM_cpp14_Release:[OK]
   v142_cpp20_Release:[ERROR]. Received:("D:/FileSubDir/FileName.ext").
   v142_cpp20_Release:[ERROR]. Received:("D:/FileSubDir/FileName.ext").
   v142_cpp17_Release:[ERROR]. Received:("D:/FileSubDir/FileName.ext").
   v142_cpp17_Release:[ERROR]. Received:("D:/FileSubDir/FileName.ext").
   v142_cpp14_Release:[OK]
   v142_cpp14_Release:[OK]
 *
 */