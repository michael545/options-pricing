# Options Pricing Models (QuantLib 1.38)

This project contains C++ code for modeling and pricing financial options using QuantLib and exploring different pricing models (European, American, and Asian options).

## Structure
- `main.cpp`: Main source file for the options pricing logic.

## Dependencies
- [QuantLib 1.38](https://www.quantlib.org/)
- [Boost C++ Libraries](https://www.boost.org/)
- C++17 or newer compiler (tested with MSYS2 g++ and Visual Studio)

## Getting Started (Windows with VS Code)

This guide provides a step-by-step process to set up the development environment, install dependencies, and build this project.

### 1. Environment Setup

**Install Prerequisites:**
1. [Git for Windows](https://gitforwindows.org/)
2. Visual Studio 2022 (Community Edition)
   - During installation, select the "Desktop development with C++" workload.
3. [Visual Studio Code](https://code.visualstudio.com/)
   - Install the "CMake Tools" extension.

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

## Notes
- For educational and prototyping purposes only.
- The Asian option Monte Carlo simulation can/will be slow for large sample sizes; change `requiredSamples` in `main.cpp` for faster testing.

## Contributing
suggestions welcome! please open an issue or PR for improvements.

## License
FOR educational use. See LICENSE file.
