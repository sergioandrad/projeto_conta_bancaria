// classes_conta.cpp

#include "classes_conta.h"

// Implementação dos métodos da classe Conta
Conta::Conta(std::string tipoConta, std::string tipoCliente, std::string dataAbertura, double saldo)
    : TipoConta(tipoConta), TipoCliente(tipoCliente), DataAbertura(dataAbertura), Saldo(saldo) {}

void Conta::sacar(double valor) {
    if (valor > Saldo) {
        throw std::runtime_error("Saldo insuficiente.");
    }
    Saldo -= valor;
}

void Conta::depositar(double valor) {
    Saldo += valor;
}

double Conta::getSaldo() const {
    return Saldo;
}

std::string Conta::getTipoConta() const {
    return TipoConta;
}

// Implementação dos métodos da classe ContaPoupanca
ContaPoupanca::ContaPoupanca(std::string tipoCliente, std::string dataAbertura, double saldo)
    : Conta("Poupanca", tipoCliente, dataAbertura, saldo) {}

double ContaPoupanca::calculaValorTarifaManutencao() const {
    return 0.0;
}

// Implementação dos métodos da classe ContaInvestimento
ContaInvestimento::ContaInvestimento(std::string tipoCliente, std::string dataAbertura, double saldo)
    : Conta("Investimento", tipoCliente, dataAbertura, saldo) {}

double ContaInvestimento::calculaValorTarifaManutencao() const {
    return 10.0;
}

// Implementação dos métodos da classe Logger
void Logger::logErro(const std::string& mensagem) {
    std::ofstream logFile("error_log.txt", std::ios_base::app);
    logFile << mensagem << std::endl;
}

// Implementação dos métodos da classe AspectoSaldo
void AspectoSaldo::verificarSaldoAntesDeSacar(Conta& conta, double valor) {
    try {
        conta.sacar(valor);
    } catch (const std::runtime_error& e) {
        std::string mensagem = "Erro ao sacar da conta " + conta.getTipoConta() + ": " + e.what();
        Logger::logErro(mensagem);
        std::cerr << mensagem << std::endl;
    }
}
