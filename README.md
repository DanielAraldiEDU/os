# Sistemas Operacionais

Repositório destinado para estudos de Sistemas Operacionais utilizando as linguagens C e Assembly.

### Ambiente

Usando o Linux, podendo ser [WSL](https://learn.microsoft.com/pt-br/windows/wsl/install) ou [CoCalc](https://cocalc.com/)

### Como gerar código Assembly a partir de um arquivo em C?

Se estiver no [WSL](https://learn.microsoft.com/pt-br/windows/wsl/install) certifique-se que você possui o [gcc](https://gcc.gnu.org/) instalado. Caso você não tenha o [gcc](https://gcc.gnu.org/) instalado execute o seguinte comando:

```bash
sudo apt install gcc
```

Após esse processo, basta selecionar o arquivo que você deseja compilar para Assembly utilizando o comando:

```bash
gcc -S main.c
```

Será gerado um novo arquivo com o **mesmo nome** do arquivo que foi compilado com a extensão `.s` no final. Neste arquivo terá todo o Assembly é gerado a partir do arquivo que foi compilado.

### Como gerar executável?

Para gerar o executável em C, basta executar o seguinte comando:

```bash
gcc -o main.exe main.c
```

Um arquivo executável com o **mesmo nome** do arquivo original será criado na **mesma raiz** no projeto.

### Como executar?

Esta etapa é válida apenas para a **execução** de arquivos em C. Tendo o executável em mãos, é necessário especificar exatamente o caminho do arquivo `.exe` que foi gerado. Levando em consideração que você fez exatamente os passos acima, basta executar o seguinte comando no terminal:

```bash
./main.exe
```

Este comando tem que ser especificado com o `./` na frente, caso não seja informado o sistema operacional não irá reconhecê-lo como um executável.

> **OBS**: O ambiente utilizado neste respositório foi o [WSL](https://learn.microsoft.com/pt-br/windows/wsl/install).
