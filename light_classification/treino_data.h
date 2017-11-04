#include <MemoryFree.h>

#define IMPUT_SIZE 30
#define SIGNAL_SIZE 5
#define BITS_PER_RAM 15
#define N_NEURONIOS 2

class Rede {

  public:

    class Neuronio {

      public:

        short* indicesDeEntradas;
        short nIndices;

        String* tabelaDeDadosKeys;
        short* tabelaDeDadosValues;
        short nDados;

        void setIndicesDeEntradas(short nIndices, short* indices) {
          this->nIndices = nIndices;
          indicesDeEntradas = (short*) malloc (nIndices * sizeof(short));
          for (short i = 0; i < nIndices; i++) {
            indicesDeEntradas[i] = indices[i];
          }
        }

        void setTabelaDeDados(short nDados, String* keys, short* values) {
          this->nDados = nDados;
          tabelaDeDadosKeys = (String*) malloc (nDados * sizeof(String));
          tabelaDeDadosValues = (short*) malloc (nDados * sizeof(short));
          for (short i = 0; i < nDados; i++) {
            tabelaDeDadosKeys[i] = keys[i];
            tabelaDeDadosValues[i] = values[i];
          }
        }


    };

    String label;
    Neuronio* neuronios[N_NEURONIOS];
    short nNeuronios = N_NEURONIOS;

    void CriarRede(String label) {
      this->label = label;
      for (short i = 0; i < nNeuronios; i++) {
        Serial.println(i);
        Serial.print("freeMemory()=");
        Serial.println(freeMemory());
        Neuronio* neuronio = new Neuronio();
        neuronios[i] = neuronio;
      }
    }

    short definirBleaching() {
      short somaHits = 0;
      short nHits = 0;
      for (short i = 0; i < nNeuronios; i++) {
        for (short j = 0; j < neuronios[i]->nDados; j++) {
          somaHits += neuronios[i]->tabelaDeDadosValues[j];
          if (neuronios[i]->tabelaDeDadosValues[j] > 0) {
            nHits++;
          }
        }
      }
      return somaHits / nHits;
    }

    short testeDeEntrada(short* entrada, short limiteDoBleaching) {
      short resultado = 0;

      for (short i = 0; i < this->nNeuronios; i++) {
        String tabelaKey = "";
        for (short j = 0; j < neuronios[i]->nIndices; j++) {
          if (entrada[neuronios[i]->indicesDeEntradas[j]] > 0) {
            tabelaKey += "1";
          } else {
            tabelaKey += "0";
          }
        }
        for (short j = 0; j < neuronios[i]->nDados; j++) {
          if (tabelaKey == neuronios[i]->tabelaDeDadosKeys[j]) {
            if (neuronios[i]->tabelaDeDadosValues[j] > limiteDoBleaching) {
              resultado++;
            }
          }
        }
      }
      return resultado;
    }
};

Rede** treinarRedesDoArquivo(Rede** redes) {

  Serial.print("freeMemory()=");
  Serial.println(freeMemory());
  short indicesfront0[15] = {17, 1, 2, 25, 14, 26, 11, 3, 27, 13, 22, 29, 10, 23, 19};
  redes[0]->neuronios[0]->setIndicesDeEntradas(15, indicesfront0);
  String keysfront0[2] = {"111111111111111", "111111111111110"};
  short valuesfront0[2] = {2, 467};
  redes[0]->neuronios[0]->setTabelaDeDados(2, keysfront0, valuesfront0);
  short indicesfront1[15] = {24, 5, 16, 21, 8, 7, 28, 0, 18, 12, 4, 9, 20, 15, 6};
  Serial.print("freeMemory()=");
  Serial.println(freeMemory());
  redes[0]->neuronios[1]->setIndicesDeEntradas(15, indicesfront1);
  String keysfront1[1] = {"111111111111111"};
  short valuesfront1[1] = {469};
  redes[0]->neuronios[1]->setTabelaDeDados(1, keysfront1, valuesfront1);
  short indicesidle0[15] = {26, 17, 25, 1, 7, 9, 19, 0, 8, 28, 3, 27, 6, 5, 15};
  redes[4]->neuronios[0]->setIndicesDeEntradas(15, indicesidle0);
  String keysidle0[1] = {"111111011111111"};
  short valuesidle0[1] = {473};
  redes[4]->neuronios[0]->setTabelaDeDados(1, keysidle0, valuesidle0);
  short indicesidle1[15] = {24, 10, 11, 20, 14, 29, 13, 12, 22, 18, 16, 2, 23, 21, 4};
  Serial.print("freeMemory()=");
  Serial.println(freeMemory());
  redes[4]->neuronios[1]->setIndicesDeEntradas(15, indicesidle1);
  String keysidle1[2] = {"111111111111111", "111111111111110"};
  short valuesidle1[2] = {373, 100};
  redes[4]->neuronios[1]->setTabelaDeDados(2, keysidle1, valuesidle1);
  short indicesright0[15] = {29, 23, 26, 15, 27, 22, 14, 19, 9, 25, 4, 24, 6, 17, 8};
  redes[3]->neuronios[0]->setIndicesDeEntradas(15, indicesright0);
  String keysright0[2] = {"111111111111111", "111111101111111"};
  short valuesright0[2] = {203, 362};
  redes[3]->neuronios[0]->setTabelaDeDados(2, keysright0, valuesright0);
  short indicesright1[15] = {0, 11, 10, 12, 28, 18, 2, 7, 13, 3, 1, 16, 21, 5, 20};
  Serial.print("freeMemory()=");
  Serial.println(freeMemory());
  redes[3]->neuronios[1]->setIndicesDeEntradas(15, indicesright1);
  String keysright1[1] = {"111111111111111"};
  short valuesright1[1] = {565};
  redes[3]->neuronios[1]->setTabelaDeDados(1, keysright1, valuesright1);
  short indicesback0[15] = {4, 6, 26, 3, 11, 27, 2, 5, 28, 12, 13, 15, 8, 17, 19};
  Serial.print("freeMemory()=");
  Serial.println(freeMemory());
  redes[1]->neuronios[0]->setIndicesDeEntradas(15, indicesback0);
  String keysback0[2] = {"111111111111111", "111111111111110"};
  short valuesback0[2] = {397, 106};
  redes[1]->neuronios[0]->setTabelaDeDados(2, keysback0, valuesback0);
  short indicesback1[15] = {10, 22, 0, 18, 1, 9, 23, 29, 20, 25, 24, 21, 7, 16, 14};
  redes[1]->neuronios[1]->setIndicesDeEntradas(15, indicesback1);
  String keysback1[1] = {"111111111111111"};
  short valuesback1[1] = {503};
  Serial.print("freeMemory()=");
  Serial.println(freeMemory());
  redes[1]->neuronios[1]->setTabelaDeDados(1, keysback1, valuesback1);
  short indicesleft0[15] = {6, 2, 12, 4, 14, 24, 21, 18, 27, 29, 1, 11, 22, 10, 23};
  redes[2]->neuronios[0]->setIndicesDeEntradas(15, indicesleft0);
  String keysleft0[1] = {"111111111111111"};
  short valuesleft0[1] = {648};
  redes[2]->neuronios[0]->setTabelaDeDados(1, keysleft0, valuesleft0);
  short indicesleft1[15] = {9, 3, 20, 28, 19, 13, 15, 16, 25, 7, 8, 17, 0, 5, 26};
  redes[2]->neuronios[1]->setIndicesDeEntradas(15, indicesleft1);
  String keysleft1[2] = {"111101111111111", "111111111111111"};
  short valuesleft1[2] = {317, 331};
  Serial.print("freeMemory()=");
  Serial.println(freeMemory());
  redes[2]->neuronios[1]->setTabelaDeDados(2, keysleft1, valuesleft1);
  Serial.print("freeMemory()=");
  Serial.println(freeMemory());





  return redes;
}

