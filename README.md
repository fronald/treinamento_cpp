# Wiselabs Software - treinamento_cpp
Treinamento básico de C++, Google Tests e HippoMocks

# Setup
- Faça fork do projeto.
- Faça clone do projeto.
- Instale o kcov (apt-get install kcov)
- Instale o GCC, G++ e MAKE (apt-get install build-essential)

# Compilando o projeto
- Entre no diretório do projeto
- Execute make clean; make

A saída será o executável dist/calculo.

# Testando o projeto
- Entre no diretório do projeto
- Execute make clean; make test

A saída será o executável dist/unit_test.

# Verificando a cobertura dos testes
- Entre no diretório do projeto
- Execute make clean; make kcov

A saída será o relatório em dist/coverage.

# Sobre o exercício

Este projeto corresponde a um executável que realiza cálculos sequenciais. Ele já possui as implementações para listar os números Primos e a Sequência de Fibonacci.
Nosso caso de uso é: O usuário entra no diretório do nosso aplicativo e executa ./calculo <INICIO> <FIM> <NOME_DO_CALCULO>. Ex: ./calculo 0 10 fibonacci

# Seu trabalho

- Implemente um cálculo para a Sequência de Golomb;
- Inicie pelo teste unitário, ou seja, este é um exercício de TDD;
- Garanta 100% de cobertura dos testes unitários mesmo nas classes que não foi você que escreveu;
- Garanta que o objeto "Interceptador" é chamado, e prove isto no teste unitário (utilizando HippoMocks).

# Importante sobre o HippoMocks

- ExpectCall: Falsifica uma chamada e ESPERA que ela seja chamada e na ORDEM declarada. Caso ela não seja chamada ou não seja chamada na ordem, o teste falhará.
- ExpectCallFunc: O mesmo que ExpectCall mas para funções estáticas.
- OnCall: Falsifica uma chamada independente dela ser utilizada durante o ciclo de vida do teste.
- OnCallFunc: O mesmo que OnCall mas para funções estáticas.










