namespace Auditorias
{
    class Equipamentos
    {
        #region Atributos
        Equipamento[] equipamentos;
        int totalEquipamento=0;
        #endregion

        #region Construtor
        public Equipamentos()
        {
            equipamentos = new Equipamento[20];
        }
        #endregion

        #region Metodos
        public bool InserirEquipamento(Equipamento equipamento)
        {
            if (totalEquipamento == equipamentos.Length)
            {
                return false;
            }
            else
            {
                equipamentos[totalEquipamento] = equipamento;
                if (totalEquipamento < equipamentos.Length)
                {
                    totalEquipamento++;
                }

            }
            return true;
        }

        #endregion



    }
}
