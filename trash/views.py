from django.shortcuts import render
from rest_framework.decorators import api_view
from rest_framework.response import Response
from rest_framework import status
import requests
from .models import User 

from .serializers import UserSerializer
from django.contrib.auth.models import User
from rest_framework.authtoken.models import Token

from django.shortcuts import get_object_or_404

from rest_framework.decorators import authentication_classes, permission_classes
from rest_framework.authentication import SessionAuthentication, TokenAuthentication
from rest_framework.permissions import IsAuthenticated

from django.http import HttpRequest, HttpResponse, JsonResponse
from django.shortcuts import redirect

UID = "u-s4t2ud-675e5069bbc568c9524d521aa9274b1df90a0e67de4c026bf7f003f5899cbdb1"
secret = "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"
auth_url = "https://api.intra.42.fr/oauth/authorize?client_id=u-s4t2ud-675e5069bbc568c9524d521aa9274b1df90a0e67de4c026bf7f003f5899cbdb1&redirect_uri=http%3A%2F%2F127.0.0.1%3A8000%2Flogin42_redir%2F&response_type=code"

@api_view(['POST'])
def signup(request):
	serializer = UserSerializer(data=request.data)
	if serializer.is_valid():
		serializer.save()
		user = User.objects.get(username=request.data['username'])
		user.set_password(request.data['password'])
		user.save()
		token = Token.objects.create(user=user)
		return Response({"token": token.key, "user": serializer.data})
	return Response(serializer.errors, status=status.HTTP_200_OK)

@api_view(['POST'])
def login(request):
	user = get_object_or_404(User, username=request.data['username'])
	if not user.check_password(request.data['password']):
		return Response({"detail": "not found."}, status=status.HTTP_404_NOT_FOUND)
	token, created = Token.objects.get_or_create(user=user)
	serializer = UserSerializer(user)
	return Response({"token": token.key, "user": serializer.data})


def home(request: HttpRequest) -> HttpRequest:
	return HttpResponse({"hello"})

def login42(request: HttpRequest):
	return redirect(auth_url)

def login42_redir(request: HttpRequest):
	code = request.GET.get('code')
	print("code ://", code)
	user = exchange_code(code)

	user_data, created = User.objects.get_or_create(
        username=user.get('login'),  # Assuming 'login' is the username from 42 API
        defaults={
            'email': user.get('email'),
            'first_name': user.get('first_name'),
            'last_name': user.get('last_name'),
            # 'avatar': user.get('image').get('link'),  # Assuming there's an image URL
        }
    )

    # if created:
    #     print(f"New user {user_data.username} created.")
    # else:
    #     print(f"User {user_data.username} already exists.")

	return JsonResponse({"msg" : user_data.username + " registred"})
	# return JsonResponse({"user" : user})

def exchange_code(code : str):
	url ="https://api.intra.42.fr/oauth/token?client_id="+UID+"&client_secret="+secret+"&code="+code+"&redirect_uri=http://127.0.0.1:8000/login42_redir/"+"&grant_type=authorization_code"
	response = requests.post(url)
	print("responce ://", response)
	# if response.status_code != 200:
    #     return response.json()  # Handle unsuccessful response
	credentials = response.json()
	print("credentials ://", credentials)
	access_token = credentials['access_token']
	response = requests.get("https://api.intra.42.fr/v2/me", headers={
		'Authorization': 'Bearer %s' % access_token
	})
	print(response)
	user = response.json()
	print("user ://", user)
	return user

