cmake_minimum_required(VERSION 3.14.0)

project(mkpoker_lookup_tables
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "Lookup tables for straights and 3/5 kickers")


add_executable(mkp_lookup_table_straight ${CMAKE_CURRENT_SOURCE_DIR}/source/mkp_lookup_table_straight.cpp)
target_compile_features(mkp_lookup_table_straight PRIVATE cxx_std_17)
target_compile_options(mkp_lookup_table_straight PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/permissive->)


add_executable(mkp_lookup_table_35 ${CMAKE_CURRENT_SOURCE_DIR}/source/mkp_lookup_table_35.cpp)
target_compile_features(mkp_lookup_table_35 PRIVATE cxx_std_17)
target_compile_options(mkp_lookup_table_35 PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/permissive->)


