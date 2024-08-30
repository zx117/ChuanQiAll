cmake_minimum_required(VERSION 3.10)
project(sqlite3)

# 定义SQLite库
add_library(sqlite3 src/sqlite3.c)

target_include_directories(
    sqlite3 PUBLIC include
)

# 选择性：设置编译选项
target_compile_options(sqlite3 PRIVATE -DSQLITE_ENABLE_FTS5)
