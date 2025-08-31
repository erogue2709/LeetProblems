select
    *
from
    students as s
    left join study_sessions as st on st.student_id = s.student_id
where
    exists (
        select
            count(subject) as tt
        from
            study_sessions
        where
            student_id = s.student_id
            and tt > 3
        group by subject
    )
order by
    st.student_id,
    st.session_date




with cte1 as(
    select
        student_id
    from
        study_sessions
    group by student_id
    having count(distinct subject)>=3
),
cte2 (id) as(
    select
        
    from
        study_sessions

)



study_sessions

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| session_id    | int     |
| student_id    | int     |
| subject       | varchar |
| session_date  | date    |
| hours_studied | decimal |
+---------------+---------+