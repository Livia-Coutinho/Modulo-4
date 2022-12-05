const jogadorAtual = document.querySelector(".jogadorAtual");

//alert('Seja bem-vindo ao Tic Tac Toe, o famoso Jogo da Velha'); 

let selecionado;
let jogador = "X";

let posicoesJogadas = [ //se alguma das posições abaixo for fechada por um mesmo símbolo, haverá um ganhador
    //Há 8 formas de ganhar o jogo, conforme disposto abaixo:
    [1, 2, 3], //horizontal 
    [4, 5, 6], //horizontal
    [7, 8, 9], //horizontal
    [1, 4, 7], //vertical
    [2, 5, 8], //vertical
    [3, 6, 9], //vertical
    [1, 5, 9], //diagonal
    [3, 5, 7], //diagonal
];

function init() {
    $.ajax({ url: "http://localhost:3000/limpar/esp", method: "GET" });
    selecionado = [];
  
    jogadorAtual.innerHTML = `Símbolo do jogador atual: ${jogador}`;
  
    document.querySelectorAll(".game button").forEach((item) => {
      item.innerHTML = "";
      item.addEventListener("click", novoMovimento);
    });
  }
  
  init();
  
  function novoMovimento(e) {
    const index = e.target.getAttribute("data-i");
    e.target.innerHTML = jogador;
    e.target.removeEventListener("click", novoMovimento);
    selecionado[index] = jogador;
  
    setTimeout(() => {
      check();
    }, [100]);
  
    jogador = jogador === "X" ? "O" : "X";
    jogadorAtual.innerHTML = `Símbolo do jogador atual: ${jogador}`;
  }
  
  function check() {
    let ultimaJogada = jogador === "X" ? "O" : "X";
  
    const items = selecionado
      .map((item, i) => [item, i])
      .filter((item) => item[0] === ultimaJogada)
      .map((item) => item[1]);
  
    for (pos of posicoesJogadas) {
      if (pos.every((item) => items.includes(item))) {

        $.ajax({
          url: "http://localhost:3000/ganhador",
          method: "POST",
          data:{
            ganhador: ultimaJogada
          }    
        })

        alert("O usuário que joga utilizando o símbolo '" + ultimaJogada + "' ganhou a partida. Parabéns!"); //alerta que informa quem ganhou o jogo
        init();
        return;
      }
    }

  
    //iniciando o jogo novamente
    if (selecionado.filter((item) => item).length === 9) {
      ultimaJogada = "EMPATE";
      $.ajax({
        url: "http://localhost:3000/ganhador",
        method: "POST",
        data: {
          ganhador: ultimaJogada
        }
      })
      alert("Não houve ganhador final. Partida em empate.");
      init();
      return;
    }
  }