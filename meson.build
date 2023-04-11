project('colors', 'cpp', version : '0.1.0', license : 'MIT', default_options : ['cpp_std=c++17'])

# Add include directories
inc = include_directories('include')

# Add source files
src = files('src/colors.cpp', 'src/style.cpp')

# Add library
lib = library('colors', src, include_directories : inc)

# Declare dependencies
colors = declare_dependency(link_with : lib, include_directories : inc)

# Add tests
test('test_compose', executable('test_compose', files('test/test_compose.cpp'), dependencies : colors, include_directories : inc))