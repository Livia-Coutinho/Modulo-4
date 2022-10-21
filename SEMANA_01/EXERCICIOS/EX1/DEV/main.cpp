//Questão 1 --> Realizar um ajuste (a partir de um min, um max e uma medida)	
//Questão 2 --> Ler um valor											        
//Questão 3 --> Função que guarde um valor a um vetor					        
//Questão 4 --> Pergunta e armazena as direções						            
//Questão 5 --> Deseja continuar										        
///////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std; //biblioteca

char *directions[4] = {(char *) "Direita", (char *)"Esquerda", (char *)"Frente", (char *)"Trás"};

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente entre dois valores 
//mínimo e máximo e retorna esse valor.

int ajusteDosValores (int minimo, int maximo, int medida) {
	medida = (medida - minimo) * 100; //Multiplicar a medida por 100 (ajuste percentual)
	int variacao = maximo - minimo;
	int resultado = medida/variacao;
	return resultado;
}
			
// 2 - Faça uma função que simule a leitura de um sensor lendo o  valor do teclado.
//Ao final a função retorna este valor

int reading (char directions) {
	int value;
	cout << "Digite um valor/a distância até: " << directions;
	cin >> value; //cin >> variável que armazena a resposta do usuário
	return value;
}

// 3 - Faça uma função que armazena uma medida inteira qualquer  em um vetor fornecido. 
//Note que como C não possui vetores nativos da linguagem, lembre-se que você precisa passar o valor máximo do 
//vetor assim como a última posição preenchida.
// Evite também que, por acidente, um valor seja escrito em uma área de memória fora do vetor

//Criar uma função para armazenar a medida inteira

int stock (int medida, int *vetor, int tamanhoMaximoVetor, int position){     //stock --> referência a armazenamento 
	if (position < tamanhoMaximoVetor) {
		vetor [position] = medida;
		position += 1; //Pega a posição inserida e indica a próxima
	}

	return position;
}         

// 4 - Faça uma função que recebe um vetor com 4 posições que contém o valor da distância de um pequeno robô 
//até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção  de maior distância 
//("Direita", "Esquerda", "Frente", "Tras") e a segunda é esta maior distância.


// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso.

//(na verdade vemos na função, lá em baixo, que retorna um ou zero)
 int desejaContinuar(){
	int resposta;
	cout << "Deseja continuar? (sim - 1, não - 0) ";
	cin >> resposta; //cin >> variável que armazena a resposta do usuário

	return resposta;
 }


// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô e através de 4 sensores em [
//cada um dos 4 pontos do robo ("Direita", "Esquerda", "Frente", "Tras"). 
// A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno para uma movimentação futura. 
// Ele vai armazenando estas distancias em um vetor fornecido como parâmetro e retorna a ultima posicao 
//preenchida do vetor.
//Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado.

// Para simular os sensores e os comandos de pare, use as funções já construídas nos ítens anteriores e 
//em um looping contínuo até que um pedido de parada seja enviado pelo usuário. 

int soma (int a, int b){
	return a+b;
}

//Complete a função com a chamada das funções já criadas
int dirige(int *vetor,int maxv){ // 
	int tamanhoMaximoVetor = maxv; //maxvetor recebe maxv  //maxVetor  --> tamanhoMaximoVetor
	int *vetorMov = vetor; //asterisco - ponteiro - referência no espaço da memória
	int positionAtualVetor = 0; //começa com zero
	int dirigindo = 1;		
	while(dirigindo){ 		
		// Inserido pelo usuário
		// Vetor
		// tamanho máx
		// posição atual
		for (int contDirections = 0; contDirections <= 3; contDirections++){    //índices de 0 a 3
			int medida = reading(*directions[contDirections]); ///Guardou o digitado pelo usuário .. Chame a função de de leitura da medida para a "DireitaChamou a função de leitrua feitata acima" 
			medida = ajusteDosValores(medida,0,830); //Função da questão um de conversão dos valores
			positionAtualVetor = stock(medida, vetorMov, tamanhoMaximoVetor, positionAtualVetor); // Chame a função para armazenar a medida no vetor vjhdk 
		} 
		///////////////////////////////////////////////////////////////////		
		// Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
		// ................
		///////////////////////////////////////////////////////////////////////////
		dirigindo = desejaContinuar();		
	}
	return positionAtualVetor;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento do robô e no final 
//percorrer o vetor e mostrar o movimento a cada direção baseado na maior distância a cada movimento.
char directionMaiorCaminho(int *vetorDeMovimentos, int *maiorDir){
	
}

void percorre(int *vetor,int tamPercorrido){		
	int *vetorDeMovimentos = vetor; //Troquei vetorMov por Vetor de Movimentos
	int maiorDir = 0;
	
	for(int i = 0; i< tamPercorrido; i+=4){
		char *direcao = directionMaiorCaminho(&(vetorDeMovimentos[i]),&maiorDir);
		printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);

	}
}

int main(int argc, char** argv) {
	int maxVetor = 100;
	int vetorMov[maxVetor*4];
	int posAtualVet = 0;
	
	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);
	
	return 0;
}