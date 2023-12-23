namespace DA_LR5;

public class EndProgram
{
    public bool End()
    {
        MassageWriter.Write(Massages.EndProgram);
        bool correctEnter = false;
        string input = string.Empty;
        bool result = false;
        while (!correctEnter)
        {
            input = Console.ReadLine() ?? string.Empty;
            if (input == "1")
            {
                correctEnter = true;
                result = true;
            }
            else if (input == "2")
            {
                correctEnter = true;
                result = false;
            }
            else
                MassageWriter.Write(Massages.IncorrectInput);
        }

        return result;
    }
}