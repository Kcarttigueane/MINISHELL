<div id="top"></div>

<!-- PROJECT LOGO -->
<br />
<h3>BUILD A SHELL</h3>
<div align="center">
    <img src="images/logo.png" alt="Logo" width="250" height="150">
</div>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
       <a href="#how-to-use">How To Use</a>
    </li>
  </ol>
</details>


<!-- ABOUT THE PROJECT -->
## About The Project
<br />

<div align="center">
    <img src="images/shell_screenshot.png" alt="Logo" width=100% height=100%>
</div>

<p align="right">(<a href="#top">back to top</a>)</p>

Le Minishell est un projet réalisé au cours de la première année d'Epitech. C'est une implémentation basique d'un interpréteur de commandes (ou Shell Unix) en C.

Implémentations :
- Récupération de l'environnement
- Gestion de l'environnement à l'aide des builtins env, setenv, unsetenv
- Gestion du prompt à l'aide des variables d'environnement USER, PWD et HOME
- Récupération des binaires à l'aide de la variable d'environnement PATH
- Exécution des binaires avec arguments
- Détection des signaux (SIGINT) et builtin "exit" implément.
- Gestion de programme segfaultant

Projet respectant la norme Epitech : Un maximum de 5 fonctions par fichier, 24 lignes par fonction et 80 colonnes par ligne.
Les fonctions autorisées sont : write, malloc, free, exit, open, close, fork, execve.

## How To Use
<br />

* First build the project executing : `make`
* Launch as normal mode with : `./mysh`
* Exit shell : `pressing ^D`

<p align="right">(<a href="#top">back to top</a>)</p>
