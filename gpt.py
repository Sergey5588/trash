import g4f


client = g4f.client.Client()
promt=input("message: ")
ans = client.chat.completions.create(
    model = "gpt-4o",
    messages=[{"role":"user", "content":promt}]

)
print(ans.choices[0].message.content)