namespace DA_LR5;

public class InputItemValidationContext
{
    public static Dictionary<string, string> Validate(string input, int size)
    {
        NumberEntriesValidator numberEntriesValidator = new NumberEntriesValidator();
        IsNumberValidator isNumberValidator = new IsNumberValidator();
        numberEntriesValidator.SetSuccessor(isNumberValidator);
        CorrectNumberItemValidator correctNumberValidator = new CorrectNumberItemValidator();
        isNumberValidator.SetSuccessor(correctNumberValidator);

        return numberEntriesValidator.HandleValidation(input, size); 
    }
}