import React, {useState} from 'react'

export default function App(){
    //Estilização do game

    const tabuleiro={ //tabu
        display: 'flex',
        flexDirection: 'column'  //tabuleiro em coluna
    }

    const LinhasDoTabuleiro={ //tabuLinha
        display: 'flex',
        flexDirection: 'row' //linha em linha
    }

    const casinha={ //casa //9casinhas //3 linhas e 3 colunas //casa que recebe os símbolos
        width: 100,
        height: 100,
        display: 'flex',
        justifyContent: 'center',
        alignItems: 'center',
        flexDirection: 'row',
        cursor: 'pointer',
        fontSize: 60,
        border: '1px solid #000'
    }

    const jogoinicial=[['', '', ''], ['', '', ''], ['', '', '']]//trocar o nome //jogo da velha é um array
                //posições vazias para constarem sem nada marcado
                //três linhas, com três colunas cada
    const [jogo, setJogo]= useState([['', '', ''], ['', '', ''], ['', '', '']])
                //define as jogadas, que serão guardadas
                //cada jogada estará em stateJogo
    const [simboloAtual, setSimboloAtual]=useState('X')
                //O símbolo atual trata-se de um X ou de um O
                //primeira jogada será um X
    const [jogando, setJogando]= useState(true)
                //Indica se o jogo está ou não ocorrendo
                //o jagando será 'false' quando algupem ganhar ou quando terminar em "velha".
                //Nesses casos o jogando recebe false

    const Tabuleiro= ()=>{ //nometrocar
        //função que retorna o tabuleiro
        //arrow function que retorna o tabuleiro do game
        //o tabuleiro retornada já está preenchido com a jogada
        //logo, para isso, o tabuleiro terá que receber o jogo
        return(
            <div style= {tabuleiro}>
            {/* /*pegando a estilização registrada no const tabuleiro no ínicio do código */}
            {/* //retorna a div com o style tabuleiro */}
                <div style={LinhasDoTabuleiro}> {/*linha um - index 0*/}
                    <div style={casinha} data-pos='00' onClick=""> {[0][0]}</div>
                    {/* preencher com o símbolo da jogada nessa posição */}
                    {/* //dado linha zero coluna zero */}
                    <div style={casinha} data-pos='01' onClick=""> {[0][1]}</div>
                    {/* //dado linha zero coluna um */}
                    <div style={casinha} data-pos='02' onClick=""> {[0][2]}</div>
                    {/* //dado linha zero coluna dois */}
                </div>
                <div style={LinhasDoTabuleiro}> {/*linha dois - index 1*/}
                    <div style={casinha} data-pos='10' onClick=""> {[1][0]}</div>
                    {/* preencher com o símbolo da jogada nessa posição */}
                    {/* //dado linha um coluna zero */}
                    <div style={casinha} data-pos='11' onClick=""> {[1][1]}</div>
                    {/* //dado linha um coluna um */}
                    <div style={casinha} data-pos='12' onClick=""> {[1][2]}</div>
                    {/* //dado linha um coluna dois */}
                </div>
                <div style={LinhasDoTabuleiro}> {/*linha três - index 2*/}
                    <div style={casinha} data-pos='20' onClick=""> {[2][0]}</div>
                    {/* preencher com o símbolo da jogada nessa posição */}
                    {/* //dado linha um coluna zero */}
                    <div style={casinha} data-pos='21' onClick=""> {[2][1]}</div>
                    {/* //dado linha um coluna um */}
                    <div style={casinha} data-pos='22' onClick=""> {[2][2]}</div>
                    {/* //dado linha um coluna dois */}
                </div>
            </div>
        )
    }

    //função que realiza checagem sobre o jogador ter ganhado
    const verificaVitoria=()=>{   //trocarnome
        //terá que verificar para X e para O
        //verificação na vertical, horizontal e diagonal
        //linhas - verificação sobre vitória nas linhas:
        let pontos=0 //
        let vitoria=false //não há como haver vitória quando o jogo está começando
        for(let l=0; l<3; l++){ //Três iterações - l iniciando em zero, l menor do que três, l++ 
            pontos=0;  //pontos iniciais
            for(let c=0; c<3; c++){ // for que percorre as colunas - para cada linha as colunas tem que se verificadas
                if(jogo[l][c] == simboloAtual){
                    pontos++ //soma-se as pontuações de vitórias
                } //se o statejogo linha coluna for igual ao símbolo atual, há uma vitória
            if(pontos >= 3){ 
                    vitoria=true //se a pontuação for igual a 3 = vitória
                    break //interromper o for
                    return 
            }

            }
        }

        //verificação nas colunas
        for (let c=0; c<3; c++){
            pontos=0
            for(let l=0; l<3; l++){
                if (jogo[l][c] == simboloAtual){
                    pontos++
                }
            }
        if(pontos >= 3){ 
            vitoria=true //se a pontuação for igual a 3 = vitória
            break //interromper o for
            return    
        }
    }
    }

    //diagonais
    jj

}

    