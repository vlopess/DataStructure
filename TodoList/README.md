# TodoList Simples em C com Integração com o Obsidian
## Versão 1.0

<img height="120" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" /><img height="120" src="https://pic4.zhimg.com/v2-958538f359123bde209d3baf7ed2b753_ipico.jpg" />          

Este é um projeto de TodoList em C que se integra com o Obsidian, permitindo que você gerencie suas tarefas e sincronize-as com o Obsidian. A facilidade que o software traz é a formatação dos dados, embora isso não seja tão complicado de se fazer manualmente.

### Versão 1.0 : Criando um simples ToDoList que salva os dados no Obsidian.

## Recursos Principais

- Criação: adicione tarefas basicas com descrição e os afazeres, sendo elas formatadas pelo programa
- Sincronização com o Obsidian: mantenha suas listas de tarefas atualizadas e sincronizadas com suas anotações no Obsidian.
- Sobre a formatação: possue uma formatação simples com um titulo, data que foi feito, uma descrição e os ToDo's, como é mostrado abaixo:
![foto do resultado](https://imgbox.com/KuFGkBGs)

## Integração com o Obsidian

Para sincronizar suas listas de tarefas com o Obsidian você deve no código mudar o path para o path dos arquivos do Obsidian da sua máquina.


```C
    char *namefile = "C:/Caminho/Para/Onde/Fica/Obsidian/";
```

## Pré-requisitos

- [GCC](https://gcc.gnu.org/) (ou outro compilador C) instalado.
- [Obsidian](https://obsidian.md/) instalado.

