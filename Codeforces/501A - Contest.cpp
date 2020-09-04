#include <iostream>

int main() {
    int pV, tV, pM, tM;
    std::cin>> pM >> pV >> tM >> tV;
    pV=std::max(3.0*pV/10, pV-(pV*tV/250.0));
    pM=std::max(3.0*pM/10, pM-(pM*tM/250.0));
    if (pV > pM) {
        std::cout << "Vasya" << std::endl;
        return 0;
    }
    if (pV < pM) {
        std::cout << "Misha" << std::endl;
        return 0;
    }
    if (pV == pM) {
        std::cout << "Tie" << std::endl;
        return 0;
    }
}
