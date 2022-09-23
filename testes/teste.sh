#!/usr/bin/env bash

setterm --term "nome do terminal"
echo "alterei o nome do terminal"

setterm --clear
echo "limpei a tela"

setterm --foreground "green"
echo "mudei a cor da fonte para verde"

setterm --background "red"
echo "mudei a cor do fundo para vermelho"

setterm --ulcolor "yellow"
echo "mudei algo para amarelo"

setterm --hbcolor "magenta"
echo "mudei algo para magenta"

setterm --bold on
echo "habilitei o negrito"
setterm --bold off

setterm --half-bright on
echo "habilitei o half-bright"
setterm --half-bright off

setterm --blink on
echo "habilitei o blink"
setterm --blink off

setterm --underline on
echo "habilitei o underline"
setterm --underline off

setterm --reverse  on
echo "habilitei o reverse"
setterm --reverse off

setterm --blank
echo "mudei algo para blank"

setterm --default
echo "mudei tudo para o padrão"
