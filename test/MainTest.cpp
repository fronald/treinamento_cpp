/* 
 * File:   Main.cpp
 * Author: fronald
 *
 * Created on 23 de Outubro de 2016, 22:43
 */

#include <cstdlib>
#include <gtest/gtest.h>

using namespace std;

/*
 * Main para execução dos testes.
 * @param argc
 * @param argv
 */
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

