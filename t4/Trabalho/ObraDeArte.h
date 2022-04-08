#include <string>
using std::string;

#ifndef OBRADEARTE_H_INCLUDED
#define OBRADEARTE_H_INCLUDED

namespace catalogo{
    class ObraDeArte{

        public:
            ObraDeArte(string, string, string, int);
            virtual int getCategoria() const = 0;
            virtual void imprimeFicha() const = 0;
            void templateFicha() const;
            string getTitulo() const;
            string getArtista() const;
            string getMaterial() const;
            int getAnoCriacao() const;
            void setTitulo(string);
            void setArtista(string);
            void setMaterial(string);
            void setAnoCriacao(int);

        private:
            string titulo, artista, material;
            int anoCriacao;
    };
}

#endif // OBRADEARTE_H_INCLUDED
