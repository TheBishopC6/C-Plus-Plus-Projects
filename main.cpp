#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int count_correct_characters(string sentence_to_type, string user_input_sentence,
int sentence_length);

float calculate_accuracy_percent(int correct_characters, int total_characters);

void show_typing_results(string user_input_sentence, int correct_characters,
int total_characters, float accuracy_percent, float typing_time_seconds);

void show_debug_info(const float *time_pointer, const float *accuracy_pointer);

void start_typing_test();

int main()
{
    char choice;
    do
    {
        start_typing_test();
        cout<<"\nTry again? (Y/N): ";
        cin>>choice;
        cin.ignore();
    }while(choice == 'y' || choice == 'Y');
    
    cout<<"\nGoodbye! keep practicing your typing.\n";
    return 0;
}

int count_correct_characters(string sentence_to_type, string user_input_sentence,
int sentence_length)
{
    int correct_characters = 0;
    for(int i = 0; i < sentence_length; i++)
    {
        if(i >= (int)user_input_sentence.size())break;
        if(sentence_to_type[i] == user_input_sentence[i])
        {
            correct_characters++;
        }
    }
    return correct_characters;
}

float calculate_accuracy_percent(int correct_characters, int total_characters)
{
    if(correct_characters == 0) return 0.0;
    return (correct_characters * 100.00f) / total_characters;
}

void show_typing_results(string user_input_sentence, int correct_characters,
int total_characters, float accuracy_percent, float typing_time_seconds)
{
    cout<<"\n=== TYPING TEST RESULTS ===\n";
    cout<<"You Typed: "<<user_input_sentence<<endl;
    cout<<"Total Characters: "<<total_characters<<endl;
    cout<<"Correct Characters: "<<correct_characters<<endl;
    cout<<"Accuracy: "<<accuracy_percent<< "%" <<endl;
    cout<<"Time taken: "<<typing_time_seconds<< "seconds" <<endl;
    
    if(typing_time_seconds  > 0)
    {
        cout<<"Typing speed: "<<total_characters / typing_time_seconds<<"Chars/sec"<<endl;
    }
    
    if(accuracy_percent == 100)
    {
        cout<<"Feedback: Perfect!\n";
    }
    else if(accuracy_percent >= 90)
    {
        cout<<"Feedback: excellent Speed and precision!\n";
    }
    else if(accuracy_percent >= 75)
    {
        cout<<"Good! Just needs more accuracy.\n";
    }
    else
    {
        cout<<"Keep practicing!\n";
    }
}

void show_debug_info(const float *time_pointer, const float *accuracy_pointer)
{
    cout<<"\n[DEBUG INFO - Read Only]\n";
    cout<<"typing_time_seconds @"<<time_pointer<< "=" <<*time_pointer<<endl;
    cout<<"accuracy_percent @"<<accuracy_pointer<< "=" <<*accuracy_pointer<<endl;
}

void start_typing_test()
{
    string sentence_to_type = "The quick brown fox jumps over the lazy dog";
    string user_input_sentence;
    string clear_input;
    
    cout<<"=== SPEED TYPING TEST===\n";
    cout<<"Type the following sentence exactly as shown:\n\n";
    cout<<sentence_to_type<<endl<<endl;
    cout<<"Press enter to start typing...";
    getline(cin, clear_input);
    getline(cin, clear_input);
    
    time_t start_time = time(0);
    cout<<"\nStart typing below and press enter when done:\n";
    getline(cin, user_input_sentence);
    time_t end_time = time(0);
    
    float typing_time_seconds = difftime(end_time, start_time);
    
    int sentence_length = 0;
    while(sentence_to_type[sentence_length] != '\0')
    {
        sentence_length++;
    }
    
    int correct_characters = count_correct_characters(sentence_to_type,
    user_input_sentence, sentence_length);
    float accuracy_percent = calculate_accuracy_percent(correct_characters,
    sentence_length);
    
    show_typing_results(user_input_sentence, correct_characters, sentence_length,
    accuracy_percent, typing_time_seconds);
    
    char debug_choice;
    cout<<"\nShow debug info? (Y/N): ";
    cin>>debug_choice;
    cin.ignore();
    
    if(debug_choice == 'y' || debug_choice == 'Y')
    {
        show_debug_info(&typing_time_seconds, &accuracy_percent);
    }
}














