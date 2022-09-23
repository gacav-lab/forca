#!/usr/bin/env bash

# data de criação: 27/10/2021

# "\033", "x1b", "x1B" ou "\e"

#define DEFAULT "\e[0m"
#define CLEAN_SCREEN "\e[H\e[2J"

cleanScreen() {
	setterm --clear
}

setFontColor() {
	if [ "$1" == "black" ] then
		setterm --foreground black
	fi

	if [ "$1" == "red" ] then
		setterm --foreground red
	fi

	if [ "$1" == "green" ] then
		setterm --foreground green
	fi

	if [ "$1" == "yellow" ] then
		setterm --foreground yellow
	fi

	if [ "$1" == "blue" ] then
		setterm --foreground blue
	fi

	if [ "$1" == "magenta" ] then
		setterm --foreground magenta
	fi

	if [ "$1" == "cyan" ] then
		setterm --foreground cyan
	fi

	if [ "$1" == "white" ] then
		setterm --foreground white
	fi

	if [ "$1" == "grey" ] then
		setterm --foreground grey
	fi
}

setFontStyle() {
	# bold
	# dark
	# italic
	# underline
	# flashing
	# hidden
	# strikethrough

	if [ "$1" == "bold" ]; then
		setterm --bold on
	fi
}

setBackgroundColor() {
	if [ "$1" == "black" ]; then
		setterm --background black
	fi

	if [ "$1" == "red" ]; then
		setterm --background red
	fi

	if [ "$1" == "green" ]; then
		setterm --background green
	fi

	if [ "$1" == "yellow" ]; then
		setterm --background yellow
	fi

	if [ "$1" == "blue" ]; then
		setterm --background blue
	fi

	if [ "$1" == "magenta" ]; then
		setterm --background magenta
	fi

	if [ "$1" == "cyan" ]; then
		setterm --background cyan
	fi

	if [ "$1" == "white" ]; then
		setterm --background white
	fi

	if [ "$1" == "grey" ]; then
		setterm --background grey
	fi
}

removeEffects() {
	setterm --default
}

if [ "$1" == "--font-color" ]; then
	setFontColor() "$2"
elif "$1" == "--font-style" ]; then
	setFontStyle() "$2"
elif "$1" == "--background-color" ]; then
	setBackgroundColor() "$2"
else
	echo "Erro: parâmetro inválido!"
fi
