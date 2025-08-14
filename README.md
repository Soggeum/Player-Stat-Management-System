# Player-Stat-Management-System
Simple Practice

# Function
- HP, MP, 공격력, 방어력을 크기 4의 int형 배열로 선언 및 0으로 초기화합니다.
  
- HP와 MP를 입력받고, HP나 MP가 하나라도 50 이하의 숫자를 입력받을 경우 다시 입력받습니다.
- HP와 MP에 값을 입력받은 후 공격력과 방어력을 입력받습니다. 공격력이나 방어력이 하나라도 0 이하의 숫자를 입력받을 경우 다시 입력 받습니다.
- 스탯 관리 시스템을 시작합니다.
    - 1번. HP 회복 / 2번. MP 회복 / 3번. HP 강화 / 4번. MP 강화 / 5번. 공격 스킬 사용 / 6번. 필살기 사용 / 7번. 프로그램 종료
    - 선택지를 출력한 후, int형 정수 하나를 입력받아서 해당 선택지를 실행합니다.
- call by pointerfh HP, MP포션은 5개씩 기본 지급되며, HP, MP 포션 개수로 5를 저장합니다. 함수는 다음과 같이 정의합니다.
    void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
- 1, 2번을 선택시 각각 HP/MP가 20 증가하고, 포션의 개수가 1개씩 차감됩니다. 포션이 0개일 경우 사용할 수 없습니다.
- 3, 4번을 선택시 각각 HP/ MP가 2배씩 증가합니다.
- 5번 선택시 MP 50을 사용하여 공격합니다
- 6번 선택시 MP의 절반을 사용하여 필살기를 씁니다.
- 7번 선택시 프로그램을 종료합니다.

# Flow Chart
<img width="362" height="1032" alt="image" src="https://github.com/user-attachments/assets/01c3ad49-609c-42e8-b51d-84f6d2b95814" />
