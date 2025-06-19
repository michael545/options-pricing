# Options Pricing Models (QuantLib 1.38)

This project contains C++ code for modeling and pricing financial options using QuantLib and exploring different pricing models (European, American, and Asian options).

## Structure
- `main.cpp`: Main source file for the options pricing logic.

## Dependencies
- [QuantLib 1.38](https://www.quantlib.org/)
- [Boost C++ Libraries](https://www.boost.org/)
- C++17 or newer compiler (tested with MSYS2 g++ and Visual Studio)

## Getting Started (Windows with VS Code)

A step-by-step process to set up the environment correctly, install dependencies, and build the target.

### 1. Environment Setup

**Install Prerequisites:**
1. [Git for Windows](https://gitforwindows.org/)
2. Visual Studio 2022 (Community Edition)
   - During install, select the "Desktop development with C++" workload.
3. [Visual Studio Code](https://code.visualstudio.com/)
   - With the "CMake Tools" extension.

**Install vcpkg Package Manager:**
Open a PowerShell terminal and run:

```powershell
cd C:\
mkdir dev
cd dev
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg integrate install
```

### 2. Install Dependencies
Install QuantLib (this may take 20-60 minutes as it builds Boost):
```powershell
.\vcpkg install quantlib\:x64-windows-static
```

### 3. Build and Run
Open in VS Code:
Open the project folder (containing CMakeLists.txt) in VS Code.

Build:

Select the kit for Visual Studio Build Tools 2022 Release - amd64 when prompted.
Click the Build button in the status bar, can also, build from the command line:

```powershell
cmake -B build -DCMAKE_TOOLCHAIN_FILE=C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build
```
 Run :
 After building, do:
```Powershell
 ./build/Release/main.exe
```

## Notes
- For educational and prototyping purposes only.
- The Asian option Monte Carlo simulation can/will be slow for large sample sizes; change `requiredSamples` in `main.cpp` for faster testing.

## Contributing
suggestions welcome! please open an issue or PR for improvements.

## License
FOR educational use. See LICENSE file.
