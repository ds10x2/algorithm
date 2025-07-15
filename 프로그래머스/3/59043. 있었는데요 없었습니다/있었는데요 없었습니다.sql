-- 보호 시작일보다 입양일이 더 빠른 동물의 아이디와 이름을 조회
-- 보호 시작일이 빠른 순으로 조회
SELECT ins.animal_id, ins.name
FROM animal_ins as ins
JOIN animal_outs as outs 
ON ins.animal_id = outs.animal_id
WHERE ins.datetime >= outs.datetime
ORDER BY ins.datetime;