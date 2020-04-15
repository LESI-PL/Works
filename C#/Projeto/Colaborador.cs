//-----------------------------------------------------------------------
// <copyright file="Colaborador.cs" company="Microsoft Corporation">
//     Copyright Microsoft Corporation. All rights reserved.
// </copyright>
// <author> Joao Pedro Marques Figueiredo </author>
// <email> joao.pedro.f93@gmail.com </email>
// <date> 4/4/2020 </date >
// <time> 00:16 </time >
// <version> 0.01 </version>
//-----------------------------------------------------------------------


using System;


namespace Projeto
{
    class Colaborador
    {
        #region Atributos      // estado ou variaveis

        int code;
        string name;
        bool active;

        #endregion


        #region Constructors
        /// <summary>
        /// Cria um novo colaborador
        /// tem o mesmo nome da classe e com objetivo de alocar espaço na memoria
        /// para receber um estado e objeto e pode ser inicializado aqui
        /// </summary>
        public Colaborador()
        {
            name = "";
            active = true;

        }
        public Colaborador(string name1, int qt_colaboradores)
        {

            name = name1;
            code = qt_colaboradores;
            active = true;

        }
        #endregion
        #region Properties
        /// <summary>
        /// Metodo que permite ter acesso ao campo code
        /// </summary>
        public int Code
        {
            get { return code; }
        }
        /// <summary>
        /// Metodo que permite ter acesso ao campo name
        /// </summary>
        public string Name
        {
            get { return Name; }     // devolve o valor do atributo
        }
        #endregion

        #region Functions


        #endregion


    }
}
