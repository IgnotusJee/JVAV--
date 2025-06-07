#!/bin/bash

# 帮助函数
print_help() {
    echo "Usage: $0 [command]"
    echo "Commands:"
    echo "  clean   : Remove build and cmake* folders"
    echo "  build   : Create build folder and run cmake/make"
    echo "  rebuild : Remove build folder and rebuild"
    echo "  test    : Run test cases 1,2,3"
    echo "  help    : Show this help message"
}

# 清理函数
clean() {
    echo "Cleaning build artifacts..."
    rm -rf build
    rm -rf cmake-*
}

# 构建函数
build() {
    if [ ! -d "build" ]; then
        mkdir build
    fi
    
    cd build || exit 1
    
    if [ -f "Makefile" ]; then
        echo "Makefile exists, skipping cmake..."
    else
        cmake ..
    fi
    
    make -j8
    cd ..
}

# 测试函数
run_tests() {
    local case_dir="cases"
    if [ ! -d "$case_dir" ]; then
        echo "Error: Case directory '$case_dir' not found!"
        exit 1
    fi
    
    cd "$case_dir" || exit 1
    
    for case_id in 1 2 3; do
        echo "Running test cases $case_id..."
        make run CASEID=$case_id
    done
    
    make clean
    cd ..
}

# 参数处理
case "$1" in
    clean)
        clean
        ;;
    build)
        build
        ;;
    rebuild)
        clean
        build
        ;;
    test)
        run_tests
        ;;
    help|"")
        print_help
        ;;
    *)
        echo "Error: Unknown command '$1'"
        print_help
        exit 1
        ;;
esac
