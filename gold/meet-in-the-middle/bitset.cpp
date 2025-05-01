#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int n;
    cout << "Quantos bits? ";
    cin >> n;

    // Atenção: std::bitset<T> exige T ser constante em tempo de compilação.
    // Se quiser usar n lido em tempo de execução, substitua por um valor fixo.
    const int BITS = 5;  // por exemplo, 5 bits
    if (n > BITS) {
        cerr << "Erro: n maior que BITS fixo (" << BITS << ")\n";
        return 1;
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        // imprime com zeros à esquerda, sempre em n colunas
        cout << bitset<BITS>(mask).to_string().substr(BITS - n) << '\n';
    }

    return 0;
}
