# 🔐 C++ Authentication System

A secure, modular, and well-structured command-line authentication system built in C++ with proper separation of concerns, security practices, and user experience considerations.

## 📁 Project Structure

```
CLI-AUTHENTICATION-CPP/
├── Authentication/               # UI Layer
│   ├── AuthService.cpp/h         # Business logic core
│   ├── Login.cpp/h               # Login interface
│   ├── Registration.cpp/h        # Registration interface
│   ├── ChangePassword.cpp/h      # Password change functionality
│   ├── Main.cpp                  # Application entry point
│   └── ...                       # Other UI components
├── InputValidators/              # Validation layer
│   ├── EmailValidator.cpp/h
│   └── PasswordValidator.cpp/h
├── Utils/                        # Utilities
│   ├── PasswordHasher.cpp/h
│   ├── Constants.h
│   └── Colors.h
├── data/                         # Data persistence
│   └── *.txt                     # User data files
├── Tests/                        # Test suite
│   └── ValidatorTests.cpp        # Input validator unit tests
├── build/                        # Compiled executables
│   ├── auth.exe                  # Main application
│   └── validator_tests.exe       # Test runner
├── .vscode/                      # Development configuration
├── makefile                      # Build automation
└── README.md                     # This file
```

## ✨ Features

### 🔐 Security First
- **Password Hashing**: No plaintext storage - passwords are securely hashed
- **Duplicate Prevention**: Prevents registration with existing usernames
- **Input Validation**: Comprehensive validation before any persistence
- **Secure Data Storage**: User credentials stored in separate, validated files
- **Password Change**: Secure password update functionality with re-authentication

### 🏗️ Clean Architecture
- **Layered Design**: Clear separation between UI, business logic, and data layers
- **Modular Components**: Independent, reusable validation and utility modules
- **Separation of Concerns**: Each component has a single, well-defined responsibility
- **Testable Components**: Dedicated test suite for validation logic

### 🎨 User Experience
- **Color-Coded CLI**: Visual feedback with distinct colors for success, errors, and hints
- **Input Validation Loops**: User-friendly prompts that guide until valid input
- **Clear Messaging**: Differentiated error messages and success confirmations
- **Intuitive Flow**: Logical progression through authentication processes

### ⚙️ Technical Excellence
- **Cross-Platform**: C++ implementation for broad compatibility
- **File-Based Persistence**: Simple yet effective data storage
- **Build Automation**: `makefile` for easy compilation and testing
- **Debugged & Tested**: Resolved path issues, parameter bugs, and linking problems
- **Unit Testing**: Comprehensive validation logic testing

## 🚀 Getting Started

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)
- Standard C++ libraries
- Make utility (for using the makefile)

### Compilation
Using the provided makefile:
```bash
# Build main application
make 

# Build test suite
make tests

# Build main suite
make run

# Clean build artifacts
make clean
```

Manual compilation:
```bash
# Main application
g++ -o build/auth.exe Authentication/*.cpp InputValidators/*.cpp Utils/*.cpp

# Test suite
g++ -o build/validator_tests.exe Tests/ValidatorTests.cpp InputValidators/*.cpp Utils/*.cpp
```

### Usage
```bash
# Run main application
./build/auth.exe

# Run validation tests
./build/validator_tests.exe
```

## 🧩 Component Details

### Authentication Layer
- **Login**: Handles user authentication with secure credential verification
- **Registration**: Manages new user creation with comprehensive validation
- **ChangePassword**: Allows authenticated users to securely update passwords
- **AuthService**: Core business logic orchestrating authentication flows

### Validation Layer
- **Email Validator**: Ensures proper email format and structure
- **Password Validator**: Enforces password strength and security policies
- **Unit Tests**: Comprehensive test suite for validation logic (ValidatorTests.cpp)

### Utility Layer
- **Password Hasher**: Implements secure password hashing algorithms
- **Constants**: Centralized configuration and constants
- **Colors**: Terminal color management for improved UX

## 🧠 System Design Notes (Scalability)

If this system needed to scale:

- **Database Migration**: Replace file-based storage with a relational database (PostgreSQL/MySQL)
- **Indexed Storage**: Store users with indexed usernames for faster lookups
- **API Layer**: Move AuthService logic behind a RESTful API for distributed access
- **Enhanced Security**: Add password salting and stronger hashing algorithms (bcrypt/argon2)
- **Rate Limiting**: Introduce rate-limiting for login attempts to prevent brute-force attacks
- **Session Management**: Implement JWT or session tokens for stateless authentication
- **Load Balancing**: Distribute authentication requests across multiple servers

The current design allows easy migration due to clean separation of layers - the data layer can be swapped without affecting business logic or UI components.

## 🛡️ Security Implementation

1. **Hashing**: Passwords are never stored in plaintext
2. **Validation**: All inputs validated before processing
3. **File Security**: Individual user files prevent bulk data exposure
4. **Input Sanitization**: Protection against malformed data
5. **Re-authentication**: Password changes require current password verification

## 📊 Data Storage

- Each user's data stored in separate `.txt` files in the `data/` directory
- File naming convention: `{username}.txt`
- Structured format for easy parsing and maintenance
- Easy migration path to database systems

## 🔧 Development Notes

This project demonstrates:
- Professional C++ project structure with proper build system
- Secure authentication implementation with test coverage
- Clean code architecture principles and separation of concerns
- User-centered CLI design with intuitive workflows
- Robust error handling and debugging practices
- Build automation with makefile for consistent compilation

## 📈 Potential Enhancements

1. **Enhanced Encryption**: Add file encryption for stored data at rest
2. **Comprehensive Logging**: Implement detailed activity and audit logging
3. **Session Management**: Add session tokens with configurable timeouts
4. **Configurable Policies**: Make password strength rules configurable
5. **Database Integration**: Replace file system with SQLite or other database backend
6. **Multi-Factor Authentication**: Add 2FA support for enhanced security
7. **Password Recovery**: Implement secure password reset functionality

## 🧪 Testing Strategy

- **Validator Unit Tests**: Comprehensive testing of input validation logic
- **Modular Testability**: Components designed for easy unit testing
- **Build Integration**: Test compilation integrated into build process
- **Data Integrity Tests**: Verification of file operations and data persistence

## 🏆 Why This Project Stands Out


- **Security-Conscious**: Implements fundamental security principles correctly
- **Maintainable Code**: Clean separation makes extension and debugging straightforward
- **User-Focused**: Despite being CLI-based, prioritizes user experience with color-coding and clear messaging
- **Test-Driven Development**: Includes validation test suite for reliability
- **Build Automation**: Professional makefile for consistent builds
- **Scalable Architecture**: Clear migration path for scaling to production environments

## 📝 License

This project is for educational and demonstration purposes, showcasing secure authentication system design principles in C++.