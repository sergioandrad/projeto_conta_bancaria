#include "classes_conta.h"

int main() {
    /* Cria uma ContaPoupanca com saldo inicial de 100.0 */
    ContaPoupanca cp("Cliente1", "2024-01-01", 100.0);

    /* Cria uma ContaInvestimento com saldo inicial de 100.0 */
    ContaInvestimento ci("Cliente2", "2024-01-01", 100.0);

    /* Tentativas de saque com verificação de saldo e logging */
    AspectoSaldo::verificarSaldoAntesDeSacar(cp, 50.0);  /* Deve funcionar */
    AspectoSaldo::verificarSaldoAntesDeSacar(cp, 60.0);  /* Deve gerar erro e log */
    AspectoSaldo::verificarSaldoAntesDeSacar(ci, 150.0); /* Deve gerar erro e log */

    return 0;
}
