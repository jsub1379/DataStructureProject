#include <vector>
#include <iostream>
/*
이걸 왜 하냐?
리플레이(다시 보는게 아니라 카트 등에서 내 고스트랑 싸울 때) 등에 사용
명령을 timestamp에과 연동해서 저장해 두었다가 다시 저장
그냥 리플레이(롤) 등에도 사용 하는듯?
*/
class ICommand
{
public:

    // 명령 실행 메소드.
    virtual void Execute() = 0;

    // 명령 반대 실행 메소드.
    virtual void Undo() = 0;
};

class CommandA : public ICommand
{
public:
    // Inherited via ICommand
    virtual void Execute() override
    {
        std::cout << "A 명령이 실행됐습니다.\n";
    }

    virtual void Undo() override
    {
        std::cout << "A 명령이 취소됐습니다.\n";
    }

private:
    const char* commandName = "A";
    int testNumber = 100;
};

class CommandB : public ICommand
{
public:
    // Inherited via ICommand
    virtual void Execute() override
    {
        std::cout << "B 명령이 실행됐습니다.\n";
    }

    virtual void Undo() override
    {
        std::cout << "B 명령이 취소됐습니다.\n";
    }
};
int main()
{
    //std::vector<ICommand*> commands;

    //commands.emplace_back(new CommandA());
    //commands.emplace_back(new CommandB());

    //for (auto* command : commands)
    //{
    //    command->Execute();
    //    //command->Undo();
    //}

    //새 객체를 만들어서 사용
    ICommand* c1 = new CommandA();
    ICommand* c2 = new CommandB();

    c1->Execute();
    c2->Execute();
    c1->Undo();
}