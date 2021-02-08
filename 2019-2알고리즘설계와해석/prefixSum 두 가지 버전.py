import time, random #time과 random 모듈 import

def prefixSum1(X, n):
	S=[0]*n #prefixSum 크기 n인 List 0으로 초기화
	S[0] = X[0] 
	for i in range(n): #n번 반복
		for j in range(1,i+1): #n번 반복
			S[i]=S[i-1]+X[i] #S[i] = X[0] + ...+X[i]
	# code for prefixSum1
	
def prefixSum2(X, n):
	S=[0]*n #prefixSum 크기 n인 List 0으로 초기화
	S[0] = X[0]
	for i in range(n): #n번 반복
		S[i]=S[i-1]+X[i] #S[i] = X[0] + ...+X[i]
	# code for prefixSum2
	
n = int(input()) #리스트 입력 크기 n을 int형으로 입력
X = [random.randint(-999, 999) for i in range(n)] #크기 n인 리스트 X를 난수로 초기화

before = time.clock() #현재 시간을 얻는다
prefixSum1(X, n) #함수prefixSum1을 호출
after = time.clock() #현재 시간을 얻는다
print(after - before) #함수 호출 전과 후의 시간차이(=함수 수행시간)

before = time.clock() #현재 시간을 얻는다
prefixSum2(X, n) #함수prefixSum2를 호출
after = time.clock() #현재 시간을 얻는다
print(after - before) #함수 호출 전과 후의 시간차이(=함수 수행시간)

random.seed()		# random 함수 초기화
# n 입력받음
# 리스트 X를 randint를 호출하여 n개의 랜덤한 숫자로 채움
# prefixSum1 호출
# prefixSum2 호출
# 두 함수의 수행시간 출력