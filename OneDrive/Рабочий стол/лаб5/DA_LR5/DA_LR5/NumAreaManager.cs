namespace DA_LR5;

public class NumAreaManager
{
    public int Manage()
    {
        MassageWriter.Write(Massages.InputArea);
        ErrorsWriters errorsWriter = new ErrorsWriters();
        bool correctEnter = false;
        string input = string.Empty;
        int result = 1;
        while (!correctEnter)
        {
            input = Console.ReadLine() ?? string.Empty;
            Dictionary<string, string> errors = InputAreaValidationContext.Validate(input, 1);
            if (errors.Count != 0)
            {
                errorsWriter.Write(errors);
                MassageWriter.Write(Massages.TryAgain);
                MassageWriter.Write(Massages.InputArea);
            }
            else
            {
                result = int.Parse(input);
                correctEnter = true;
            }
                
        }

        return result;
    }
}