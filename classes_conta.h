/* Código que implementa uma classe mãe denominada Conta e classes filhas ContaPoupanca e ContaInvestimento dotadas de métodos para manipulação e validação do saldo */
#ifndef CLASSES_CONTA_H
#define CLASSES_CONTA_H

#include <iostream>   /* Biblioteca para entrada e saída padrão */
#include <string>     /* Biblioteca para manipulação de strings */
#include <stdexcept>  /* Biblioteca para manipulação de exceções padrão */
#include <fstream>    /* Biblioteca para manipulação de arquivos */

class Conta {
protected:
    std::string TipoConta;     /* Tipo da conta, por exemplo, Corrente, Poupança */
    std::string TipoCliente;   /* Tipo de cliente, por exemplo, Individual, Empresarial */
    std::string DataAbertura;  /* Data de abertura da conta */
    double Saldo;              /* Saldo da conta */

public:
    /* Construtor da classe Conta, inicializa os membros com os valores fornecidos */
    Conta(std::string tipoConta, std::string tipoCliente, std::string dataAbertura, double saldo);
    /* Destrutor virtual para garantir a destruição correta de objetos derivados */
    virtual ~Conta() = default;
    /* Método virtual puro para calcular a tarifa de manutenção, deve ser implementado nas classes derivadas */
    virtual double calculaValorTarifaManutencao() const = 0;
    /* Método para sacar dinheiro da conta */
    void sacar(double valor);
    /* Método para depositar dinheiro na conta */
    void depositar(double valor);
    /* Retorna o saldo atual da conta */
    double getSaldo() const;
    /* Retorna o tipo da conta */
    std::string getTipoConta() const;
};

class ContaPoupanca : public Conta {
public:
    /* Construtor da classe ContaPoupanca, inicializa a Conta base */
    ContaPoupanca(std::string tipoCliente, std::string dataAbertura, double saldo);

    /* Implementação do método para calcular a tarifa de manutenção (tarifa zero para poupança) */
    double calculaValorTarifaManutencao() const override;
};

class ContaInvestimento : public Conta {
public:
    /* Construtor da classe ContaInvestimento, inicializa a Conta base */
    ContaInvestimento(std::string tipoCliente, std::string dataAbertura, double saldo);

    /* Implementação do método para calcular a tarifa de manutenção (tarifa fixa para investimento) */
    double calculaValorTarifaManutencao() const override;
};

class Logger {
public:
    /* Método estático para registrar mensagens de erro em um arquivo */
    static void logErro(const std::string& mensagem);
};

class AspectoSaldo {
public:
    /* Método estático para verificar o saldo antes de permitir um saque */
    static void verificarSaldoAntesDeSacar(Conta& conta, double valor);
};

#endif // CLASSES_CONTA_H