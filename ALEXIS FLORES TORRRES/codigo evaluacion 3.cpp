#include <iostream>//libreria para tener acceso adispositivos de entrada y salida.
#include <string>//libreria permite almacena caracteres como objeto.
#include <map> //libreria que recupera eficazmente valores de elementos.
#include <cstdlib> //libreria Para generar números aleatorios.
#include <ctime>//libreria que utiliza un formato de reloj(en esete caso ayuda a variar las respuestas de lugar


//aqui tenemos las preguntas con su respectiva respuesta. 
std::map<std::string, std::string> questionsAndAnswers = {
	{"Quien es herman@ de Garen?", "Lux"},
{"Quien es el personaje mas poderoso segun el lore de lol?", "bardo"},
	{"Quien dio vida al personaje de Blitzcrank?", "Viktor"},
{"Quien es el rey de frieljord?", "tryndamere"},
	{"Que personaje puede retroceder en el tiempo?", "ekko"},
{"que personaje es desendiente de azir?", "sivir"},
	{"Quien es el personaje mas antiguo de lol?", "annie"},
{"Quien dio origen a warwick?", "singed"},
	{"que personaje gobierna demacia?", "jarvan"},
{"Quien apuñalo a sivir?", "cassiopea"}
};

//aqui nos encargamos de definir las opciones.
void showOptions() {
	std::cout << "Opciones de respuesta:" << std::endl;
	std::cout << "1. A" << std::endl;
	std::cout << "2. B" << std::endl;
	std::cout << "3. C" << std::endl;
	std::cout << "4. D" << std::endl;
	std::cout << "5. E" << std::endl;
	std::cout << "6. F" << std::endl;
}

//funcion principal.
int main() {
	int points = 0;
	char option;
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // se encarga de cambiar el lugar de las respuestas (en este caso)de forma aleatoria
	
	// mensaje de bienvenida.
	std::cout << "!Bienvenido al juego de trivia de League of Legends!" << std::endl;
	
	for (const auto& questionAnswer : questionsAndAnswers) {
		std::string question = questionAnswer.first;
		std::string correctAnswer = questionAnswer.second;
		
		//se encarga generar un número aleatorio para seleccionar la opción correcta.
		int correctOption = std::rand() % 6 + 1;
		
		std::cout << question << std::endl;
		
		// se encarga de poner opciones random junto a la respuesta correcta para agregarle dificultad.  
		switch (correctOption) {
		case 1:
			std::cout << "A. " << correctAnswer << std::endl;
			std::cout << "B. samira" << std::endl;
			std::cout << "C. zilean" << std::endl;
			std::cout << "D. katarina" << std::endl;
			std::cout << "E. quinn" << std::endl;
			std::cout << "F. xin xao" << std::endl;
			break;
		case 2:
			std::cout << "A. ashe" << std::endl;
			std::cout << "B. " << correctAnswer << std::endl;
			std::cout << "C. akshan" << std::endl;
			std::cout << "D. neeko" << std::endl;
			std::cout << "E. volibear" << std::endl;
			std::cout << "F. renekton" << std::endl;
			break;
		case 3:
			std::cout << "A. darius" << std::endl;
			std::cout << "B. teemo" << std::endl;
			std::cout << "C. " << correctAnswer << std::endl;
			std::cout << "D. lissandra" << std::endl;
			std::cout << "E. zilean" << std::endl;
			std::cout << "F. akali" << std::endl;
			break;
		case 4:
			std::cout << "A. aurelion" << std::endl;
			std::cout << "B. zilean" << std::endl;
			std::cout << "C. sejuani" << std::endl;
			std::cout << "D. " << correctAnswer << std::endl;
			std::cout << "E. quinn" << std::endl;
			std::cout << "F. xin xao" << std::endl;
			break;
		case 5:
			std::cout << "A. ashe" << std::endl;
			std::cout << "B. akali" << std::endl;
			std::cout << "C. neeko" << std::endl;
			std::cout << "D. nasus" << std::endl;
			std::cout << "E. " << correctAnswer << std::endl;
			std::cout << "F. lucian" << std::endl;
			break;
		case 6:
			std::cout << "A. darius" << std::endl;
			std::cout << "B. lee sin" << std::endl;
			std::cout << "C. senna" << std::endl;
			std::cout << "D. zoe" << std::endl;
			std::cout << "E. shen" << std::endl;
			std::cout << "F. " << correctAnswer << std::endl;
			break;
		}
		
		//aqui nos permite seleccionar una opcion en formato letra(lo configure para que se pueda hacer con mayuscula o minuscula.
		std::cout << "Elige una opcion: ";
		std::cin >> option;
		
		if (option == 'A'&& correctOption == 1 ||
			option == 'B'&& correctOption == 2 ||
			option == 'C'&& correctOption == 3 ||
			option == 'D'&& correctOption == 4 ||
			option == 'E'&& correctOption == 5 ||
			option == 'F'&& correctOption == 6 ||
			option == 'a'&& correctOption == 1 ||
			option == 'b'&& correctOption == 2 ||
			option == 'c'&& correctOption == 3 ||
			option == 'd'&& correctOption == 4 ||
			option == 'e'&& correctOption == 5 ||
			option == 'f'&& correctOption == 6) {
			std::cout << "¡Respuesta correcta! Sumas 10 puntos." << std::endl;
			points += 10;
		} else {
			std::cout << "Respuesta incorrecta. Pierdes 5 puntos." << std::endl;
			points -= 5;
		}
	}
	
	// aqui sumara el valor de los puntos y dependiendo de si este es mayor a 90 puntos dara un mensaje de you win o game over. 
	std::cout << "Fin del juego. Tu puntuacion final es: " << points << " puntos." << std::endl;
	if (points >= 90) {
		std::cout << "!You Win!" << std::endl;
	} else {
		std::cout << "!Game Over!" << std::endl;
	}
	
	return 0;
}
