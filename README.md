# Sistemas Operacionais

Repositório destinado para estudos de Sistemas Operacionais utilizando as linguagens C e Assembly.

### Ambiente

Usando o Linux, podendo ser [WSL](https://learn.microsoft.com/pt-br/windows/wsl/install) ou [CoCalc](https://cocalc.com/)

### Como executar?

Se estiver no [WSL](https://learn.microsoft.com/pt-br/windows/wsl/install) certifique-se que você possui o [gcc](https://gcc.gnu.org/) instalado. Caso você não tenha o [gcc](https://gcc.gnu.org/) instalado execute o seguinte comando:

```bash
sudo apt install gcc
```

Após esse processo, basta selecionar o arquivo que você deseja compilar para Assembly utilizando o comando:

```bash
gcc -S main.c
```

Será gerado um novo arquivo com o **mesmo nome** do arquivo que foi compilado com a extensão `.s` no final. Neste arquivo terá todo o Assembly é gerado a partir do arquivo que foi compilado.

> **OBS**: O ambiente utilizado neste respositório foi o [WSL](https://learn.microsoft.com/pt-br/windows/wsl/install).
