const int ValorAr = 437;    // leitura no ar valor de calibração
const int ValorAgua = 187;  //leitura na água valor de calibração
const int maximo = 81;
const int minimo = 54;

int valorUmidadeSolo = 0;
float porcentagemUmidade = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  valorUmidadeSolo = analogRead(A2);

  int faixa = ValorAr - ValorAgua;

  int distancia = ValorAr - valorUmidadeSolo;

  porcentagemUmidade = (float)distancia / faixa * 100.0;

  if (porcentagemUmidade < 0) porcentagemUmidade = 0;
  if (porcentagemUmidade > 100) porcentagemUmidade = 100;

  Serial.print("UmidadeMax:"); //Umidade maxima adequada para manter o café. 
  Serial.print(maximo);
  Serial.print("  ");
  Serial.print("UmidadeMin:"); //Umidade minima adequada para manter o café. 
  Serial.print(minimo);
  Serial.print("  ");
  Serial.print("UmidadeAtual:");
  Serial.println(porcentagemUmidade);
  //codigo para visualizar o grafico(Serial Plotter)
    
  delay(1000);

}





